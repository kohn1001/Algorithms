"""
 solution in Python to the problem of finding a local mininum in array - JP Morgan interview question:
    here is the description of the problem in GeeksForGeeks:
        http://www.geeksforgeeks.org/find-local-minima-array/

        =================>>>>>> if you are using this repo and reading this solution please follow me, it the least you can do for me :)
"""
def find_loc_mid(arr):
    print (arr)
    mid = len(arr)/2
    print mid
    if mid == 0 or arr[mid-1] > arr[mid] and mid == len(arr)-1 or arr[mid] < arr [mid+1]:
        return mid
    if mid > 0 and arr[mid -1] < arr[mid]:
        return find_loc_mid(arr[:mid])
    print arr[mid:]
    return find_loc_mid(arr[mid+1:])


arr = [15, 4, 11, 9, 0]
idx = find_loc_mid(arr)
print('local min at: ' , idx, 'local mid is: ', arr[idx])
