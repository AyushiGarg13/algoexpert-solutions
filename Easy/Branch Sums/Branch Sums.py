class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def helper(node: BinaryTree, branch, array):
    if node != None:
        branch += node.value
        if node.left == None and node.right == None:
            array.append(branch)
            return
        helper(node.left, branch, array)
        helper(node.right, branch, array)


def branchSums(root):
    array = []
    helper(root, 0, array)
    return array
