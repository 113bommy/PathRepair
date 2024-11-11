import collections
s, k = input().split()
arr = list(map(int,list(s[1:])))
n = 0;
def cor(n,arr):
    for i in range(0,n):
        if arr[-(i+1)]!=0:
            return False
    return True
if len(s)<int(k):
    print(len(s)-1)
else:
    for i in range(len(arr)-1,-1,-1):
        if arr[i]!=0:
            arr.pop(i)
            n+=1
            if len(arr)>=int(k) and cor(int(k),arr):
                break
        if len(arr)<int(k):
            n = len(s)-1
            break
    print(n)







