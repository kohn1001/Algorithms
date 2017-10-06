
"""
Using bit manipulation to determine whether all characters in a string are unique 

"""

def is_unique(st):
    mask = 0
    for s in st:
        os = ord(s) - ord('A')
        if mask & (1 << os):
            print ('{} is not unique'.format(s))
        else:
            print ('{} is unique '.format(s))
            mask |= 1 << os

is_unique('abAABcdee')
