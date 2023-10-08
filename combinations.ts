// function recurse(arr: number[], output: number[][]) {
//   if (arr.length === 1) {
//     return arr;
//   }

// }

// function findCombinations(arr: number[]) {
//   for (let i = 0; i < arr.length; i++) {
//     recurse(arr.slice(i + 1), []);
//   }
// }

// findCombinations([1, 2, 3]);

function permutes(nums: number[]): number[][] {
  const result: number[][] = [];

  function backtrack(start: number) {
    if (start === nums.length - 1) {
      result.push([...nums]);
      return;
    }

    for (let i = start; i < nums.length; i++) {
      // Swap nums[start] and nums[i]
      [nums[start], nums[i]] = [nums[i], nums[start]];

      // Recursively generate permutations for the remaining elements
      backtrack(start + 1);

      // Swap back to the original state to explore other possibilities
      [nums[start], nums[i]] = [nums[i], nums[start]];
    }
  }

  backtrack(0);
  return result;
}

// Example usage:
const inputArray = [1, 2, 3];
const permutations = permutes(inputArray);
console.log(permutations);
