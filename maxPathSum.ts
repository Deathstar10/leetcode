class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}
function maxPathSum(root: TreeNode | null): number {
  let maxSum = Number.MIN_SAFE_INTEGER;

  function returnSumNode(root: TreeNode | null): number {
    if (root === null) {
      return 0;
    }

    const leftSum = Math.max(0, returnSumNode(root.left));
    const rightSum = Math.max(0, returnSumNode(root.right));

    const currentSum = root.val + leftSum + rightSum;

    if (currentSum > maxSum) {
      maxSum = currentSum;
    }

    return root.val + Math.max(leftSum, rightSum);
  }

  returnSumNode(root);

  return maxSum;
}

// maxPathSum([-10, 9, 20, null, null, 15, 7]);
