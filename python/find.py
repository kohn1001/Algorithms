""""

I've found this question when browsing the web, DropBox interview question.

This script calculate a md5sum for each file in the directory you run it from (and recursively in the sub directories as well
----> DFS)

If there may be files with the same content you should get it in a list greater then 1.

For example if 2 files have the same content and their md5sum is: 'd430c68778e3cb4a8d17d24e7ddc1ae4'

you should get: {'d430c68778e3cb4a8d17d24e7ddc1ae4', [<path to file1>, <path to file2>]}
otherwise you 
just get:       {'d430c68778e3cb4a8d17d24e7ddc1ae4', [<path to file1>]}

Take it to your computer and just run it and see
"""
import os
import hashlib
from collections import defaultdict

def find_dup(path_name, dup_list):
    list_dir = os.listdir(path_name)
    for d in list_dir:
        d_full_path = path_name + '/' + str(d)
        if os.path.isdir(d):
            find_dup(d_full_path, dup_list)
        else:
            cont = hashlib.md5(open(d_full_path, 'rb').read()).hexdigest()
            dup_list[cont].append(d_full_path)
    return 

my_dict = defaultdict(list)

"""
Pay attention --> similar to Java objects are passed by ref - for that matter we are sending my_dict and 
find_dup is changing it (this code in C/C++ would return my_dict empty - because in C/C++ if not explicit - objects and primitives
are passed to function  by value)

"""
find_dup(os.getcwd(), my_dict)
print(my_dict)
