function nextPermutation(nums: number[]) {
  let arrayLength = nums.length;
  for (var i = arrayLength - 1; i > 0; i--) {
    if (nums[i] > nums[i - 1]) {
      break;
    }
  }

  if (i === 0) {
    nums = nums.reverse();
    return nums;
  }
  for (var j = arrayLength - 1; j >= 0; j--) {
    if (nums[j] > nums[i - 1]) {
      break;
    }
  }

  // swap the elements, where the number is close to the the replacing element.
  [nums[i - 1], nums[j]] = [nums[j], nums[i - 1]];
  console.log(nums.slice(i).sort());
  nums = nums.slice(0, i).concat(nums.slice(i).sort());
  console.log(nums);

  return nums;
}

var arr = [2, 1, 5, 4, 3, 0, 0];
nextPermutation(arr);

console.log(arr);
