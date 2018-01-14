def merge(left_arr, right_arr):
    
    res = []
    li = 0
    ri = 0

    while li < len(left_arr) and ri < len(right_arr):
        if left_arr[li] <= right_arr[ri]:
            res.append(left_arr[li])
            li += 1
        else:
            res.append(right_arr[ri])
            ri += 1 
    while li < len(left_arr):
        res.append(left_arr[li])
        li += 1
    while ri < len(right_arr):
        res.append(right_arr[ri])
        ri += 1
    
    return res


def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr)/2
    res_left = merge_sort(arr[:mid])
    res_right = merge_sort(arr[mid:])
    res = merge(res_left, res_right)
    return res



#res = merge([1, 5, 7, 25], [2, 4, 37, 95])
res = merge_sort([1, -7, 25, 35, 2, 4, 7 ,3, 15])

for i in res:
    print i
