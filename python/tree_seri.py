"""
    I have a better version here: 
    https://github.com/kohn1001/Algorithms/blob/master/python/des_n_serialize_tree.py
    But I leave this one to have a nother way of implementation

    here is a better version 

"""
file_name = 'serialize_tree'

class Node:
    def __init__(self, val=None):
        self.val = val
        self.right = None
        self.left = None


def print_tree(root):
    if root is None:
        return
    print_tree(root.left)
    print(root.val)

    print_tree(root.right)

def serialize_aux(root, file_it):
    if root == None:
        file_it.write('null' + ' ')
        return
    c = str(root.val)
    c += " "
    file_it.write(c)
    serialize_aux(root.left, file_it)
    serialize_aux(root.right, file_it)

def serialize(root):
    file_it = open(file_name, 'w')
    serialize_aux(root, file_it)


from collections import deque
def de_serialize_aux(fi):
    if len(fi) == 0: return None
    val = fi[0]
    fi.popleft()
    if val == 'null':
        return None
    root = Node(val)
    root.left = de_serialize_aux(fi)
    root.right = de_serialize_aux(fi)
    return root


def de_serialize():
    #should use with - but haven't for the non-Python readers
    fi = open(file_name)
    for f in fi:
        des_tree = f.split(" ")
    print des_tree
    des_tree = deque(des_tree)
    root = de_serialize_aux(des_tree)
    fi.close()
    return root

'''
            5
          /   \
         7     3
                \
                 4
'''
root = Node(5)
root.right = Node(3)
root.left = Node(7)
root.right.right = Node(4)

print_tree(root)
serialize(root)
new_root = de_serialize()
print_tree(new_root)

'''
        75
      /   \
     7    13
      \   / \
      10  9  7
              \
               4



'''


root = Node(75)
root.right = Node(13)
root.left = Node(7)
root.right.right = Node(7)
root.right.left = Node(9)
root.left.right = Node(10)
root.right.right.right = Node(4)
print ('new tree')
print_tree(root)
serialize(root)
new_root = de_serialize()
print_tree(new_root)
