

from sets import Set
from collections import defaultdict

def is_in_dict(word):
    m_dict = { 'VANA', 'NER', 'NERVANA', 'NERV', 'ANA'}
    if word in m_dict:
        return True
    return False


def get_letter_from_key(key):
    return { 
    2 : 'ABC',
    3 : 'DEF',
    4 : 'GHI',
    5 : 'JKL',
    6 : 'MNO',
    7 : 'PQRS',
    8 : 'TUV',
    9 : 'WXYZ'
    } [key]


def check_valid_insert(word, res):
    if is_in_dict(word):
        res.add(word)
    if is_in_dict(word[:3]) and is_in_dict(word[3:]):
        w = word[:3] +'_' + word[3:]
        res.add(w)
    #print word[3:]
    if is_in_dict(word[:4]) and is_in_dict(word[4:]):
        w = word[:4] +'_' + word[4:]
        res.add(w)

def get_words(num, idx):
    res = Set()
    if idx == len(num):
        res.add('')
        return res
    dig = num[idx]
    letters = get_letter_from_key(num[idx])
    words_so_far = get_words(num, idx+1)
    for w in words_so_far:
        for l in letters:
            r = l + w
            if len(r) < len(num) :
                res.add(r)
            if len(r) == len(num):
                check_valid_insert(r, res)
    return res

#res= get_words([3, 7, 6, 7, 2, 6, 9], 0)
res= get_words([6, 3, 7, 8, 2, 6, 2], 0)
#print arr[:3]

for r in res:
    print(r)
