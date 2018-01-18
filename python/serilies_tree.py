
import os
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

    def get_key(self):
        return self.key

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right

    def insert_node(self, root, key):
        to_insert = TreeNode(key)
        curr = root
        while curr:
            if curr.get_key() < key:
                if curr.right == None:
                    curr.right = to_insert
                    return to_insert
                curr = curr.right
            elif curr.get_key() > key:
                if curr.left == None:
                    curr.left = to_insert
                    return to_insert
                curr = curr.left
        return None

    def serilize_tree_util(self, f, node):
        if node == None:
            f.write('None\n')
            return 
        f.write(str(node.get_key())+'\n')
        self.serilize_tree_util(f, node.left)
        self.serilize_tree_util(f, node.right)
     
    def deserilize_tree_utils(self, f):
        key = f.read().strip()
        node = TreeNode(key)
        if not key:
            print (ord(key))
        if not key or 'None' == key:
            return None
        node.left = self.deserilize_tree_utils(f)
        node.right = self.deserilize_tree_utils(f)
        return node

    def serilize_tree(self, file_name, root):
        with open(file_name, 'w') as f:
            self.serilize_tree_util(f, root)

    def deserilize_tree(self, file_name):
        with open(file_name) as f:
            return self.deserilize_tree_utils(f)

def print_tree(root):
    if root == None:
        return
    print_tree(root.get_left())
    print(root.get_key())
    print_tree(root.get_right())


tree = TreeNode(15)
tree.insert_node(tree, 10)
tree.insert_node(tree, 11)
tree.insert_node(tree, 21)
tree.insert_node(tree, 17)
tree.insert_node(tree, 35)

path =  os.path.join(os.getcwd(), 'ser_tree')
print path
tree.serilize_tree(path, tree)
new_tree = tree.deserilize_tree(path)
print_tree(new_tree)


