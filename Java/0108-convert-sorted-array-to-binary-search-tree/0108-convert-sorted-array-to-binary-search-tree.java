class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {

        return construct(nums, 0, nums.length - 1);
    }

    public TreeNode construct(int[] nums, int left, int right) {

        if (left > right) {
            return null;
        }

        int mid = left + (right - left) / 2;

        TreeNode root = new TreeNode(nums[mid]);

        root.left = construct(nums, left, mid - 1);

        root.right = construct(nums, mid + 1, right);

        return root;
    }
}