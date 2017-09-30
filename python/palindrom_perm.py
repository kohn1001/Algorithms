from collections import Set

def is_pali_perm(str_in):
    char_hash = set()
    for c in str_in:
        if c in char_hash:
            char_hash.remove(c)
        else:
            char_hash.add(c)
    if len(char_hash) == 0 or len(char_hash) == 1:
        return True
    return False

str_in = raw_input()
if is_pali_perm(str_in):
    print ('String is pali perm')
else:
    print ('String is not pali perm')
