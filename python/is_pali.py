def is_pali(s):
    start = 0
    end = len(s)-1

    while start < end:
        if s[start] is not s[end]:
            return False
        start += 1
        end -= 1
    return True

res = is_pali('aacbaa')
if res:
    print ('is pali')
else:
    print ('is not pali')
