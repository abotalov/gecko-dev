// |reftest| skip-if(!this.hasOwnProperty("SIMD"))
var BUGNUMBER = 946042;
var float32x4 = SIMD.float32x4;
var int32x4 = SIMD.int32x4;

var summary = 'int32x4 sub';

function test() {
  print(BUGNUMBER + ": " + summary);

  // FIXME -- Bug 948379: Amend to check for correctness of border cases.

  var a = int32x4(1, 2, 3, 4);
  var b = int32x4(10, 20, 30, 40);
  var c = SIMD.int32x4.sub(b,a);
  assertEq(c.x, 9);
  assertEq(c.y, 18);
  assertEq(c.z, 27);
  assertEq(c.w, 36);

  if (typeof reportCompare === "function")
    reportCompare(true, true);
}

test();

