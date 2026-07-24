// Self-contained RFC 4122 UUID version 5 implementation (SHA-1 based),
// behavior-compatible with the `v5` export of the npm `uuid` package.
// Classic script: exposes `uuidv5(name, namespaceUuidString)` as a global.

(function (global) {
  'use strict';

  // SHA-1 (RFC 3174) over an array of bytes, returns 20 bytes
  function sha1(bytes) {
    var padded = bytes.slice();
    var byteLength = bytes.length;
    padded.push(0x80);
    while (padded.length % 64 !== 56) {
      padded.push(0);
    }
    var bitLengthHi = Math.floor(byteLength / 0x20000000);
    var bitLengthLo = (byteLength << 3) >>> 0;
    var i;
    for (i = 3; i >= 0; i--) {
      padded.push((bitLengthHi >>> (i * 8)) & 0xff);
    }
    for (i = 3; i >= 0; i--) {
      padded.push((bitLengthLo >>> (i * 8)) & 0xff);
    }

    var h0 = 0x67452301, h1 = 0xefcdab89, h2 = 0x98badcfe, h3 = 0x10325476, h4 = 0xc3d2e1f0;
    var w = new Array(80);

    for (var block = 0; block < padded.length; block += 64) {
      var t;
      for (t = 0; t < 16; t++) {
        w[t] = (padded[block + t * 4] << 24) |
               (padded[block + t * 4 + 1] << 16) |
               (padded[block + t * 4 + 2] << 8) |
               padded[block + t * 4 + 3];
      }
      for (t = 16; t < 80; t++) {
        var x = w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16];
        w[t] = (x << 1) | (x >>> 31);
      }

      var a = h0, b = h1, c = h2, d = h3, e = h4;
      for (t = 0; t < 80; t++) {
        var f, k;
        if (t < 20) { f = (b & c) | (~b & d); k = 0x5a827999; }
        else if (t < 40) { f = b ^ c ^ d; k = 0x6ed9eba1; }
        else if (t < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8f1bbcdc; }
        else { f = b ^ c ^ d; k = 0xca62c1d6; }
        var temp = ((((a << 5) | (a >>> 27)) >>> 0) + f + e + k + w[t]) >>> 0;
        e = d;
        d = c;
        c = ((b << 30) | (b >>> 2)) >>> 0;
        b = a;
        a = temp;
      }

      h0 = (h0 + a) >>> 0;
      h1 = (h1 + b) >>> 0;
      h2 = (h2 + c) >>> 0;
      h3 = (h3 + d) >>> 0;
      h4 = (h4 + e) >>> 0;
    }

    var digest = [];
    [h0, h1, h2, h3, h4].forEach(function (h) {
      digest.push((h >>> 24) & 0xff, (h >>> 16) & 0xff, (h >>> 8) & 0xff, h & 0xff);
    });
    return digest;
  }

  function utf8Bytes(str) {
    var bytes = [];
    for (var i = 0; i < str.length; i++) {
      var code = str.charCodeAt(i);
      if (code < 0x80) {
        bytes.push(code);
      } else if (code < 0x800) {
        bytes.push(0xc0 | (code >> 6), 0x80 | (code & 0x3f));
      } else if (code < 0xd800 || code >= 0xe000) {
        bytes.push(0xe0 | (code >> 12), 0x80 | ((code >> 6) & 0x3f), 0x80 | (code & 0x3f));
      } else {
        // surrogate pair
        i++;
        code = 0x10000 + (((code & 0x3ff) << 10) | (str.charCodeAt(i) & 0x3ff));
        bytes.push(
          0xf0 | (code >> 18),
          0x80 | ((code >> 12) & 0x3f),
          0x80 | ((code >> 6) & 0x3f),
          0x80 | (code & 0x3f)
        );
      }
    }
    return bytes;
  }

  function parseUuid(uuidString) {
    var hex = String(uuidString).replace(/-/g, '');
    if (hex.length !== 32 || /[^0-9a-fA-F]/.test(hex)) {
      throw new TypeError('Invalid UUID: ' + uuidString);
    }
    var bytes = [];
    for (var i = 0; i < 32; i += 2) {
      bytes.push(parseInt(hex.substring(i, i + 2), 16));
    }
    return bytes;
  }

  function stringifyUuid(bytes) {
    var hex = bytes.map(function (b) {
      return (b + 0x100).toString(16).substring(1);
    }).join('');
    return hex.substring(0, 8) + '-' +
           hex.substring(8, 12) + '-' +
           hex.substring(12, 16) + '-' +
           hex.substring(16, 20) + '-' +
           hex.substring(20);
  }

  function uuidv5(name, namespace) {
    var bytes = parseUuid(namespace).concat(utf8Bytes(String(name)));
    var hash = sha1(bytes).slice(0, 16);
    hash[6] = (hash[6] & 0x0f) | 0x50; // version 5
    hash[8] = (hash[8] & 0x3f) | 0x80; // RFC 4122 variant
    return stringifyUuid(hash);
  }

  global.uuidv5 = uuidv5;
})(typeof window !== 'undefined' ? window : globalThis);
