from collections import Counter

def solve(str,k):
    mp = Counter(str)
    mp=dict(mp)
    print(mp)

    kstring = ""
    for key,val in mp.items():
        if(val%k!=0):
            return -1
        else:
            #print val
            kstring += key*(int(val/k))

    #print result
    result = ""
    for i in range(0,k):
        result += kstring

    return result


k = int(input())
str = input()

print(solve(str,k))
"""
2
aazz
"""