# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        node = TreeNode(val)
        if not root:
            root = node
            return root
        if not root.left and val < root.val:
            root.left = node
        elif not root.right and val > root.val:
            root.right = node
        elif val < root.val:
            self.insertIntoBST(root.left,val)
        else:
            self.insertIntoBST(root.right,val)

        return root
        