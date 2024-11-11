n = int(input())
arr = list(map(int,input().split()))
c = max(arr)
d = min(arr)
if arr.count(c)==1 and arr.count(d)==1:
    if arr.index(d)>arr.index(c):
        print((arr.index(c))+len(arr)-arr.index(d)-1)
    else:
        print(((arr.index(c)) + len(arr) - arr.index(d) - 1)-1)
else:
    if arr.index(c)<=len(arr)-arr[::-1].index(d):
        print((arr.index(c))+arr[::-1].index(d))
    else:
        print((arr.index(c)) + (arr[::-1].index(d))-1)