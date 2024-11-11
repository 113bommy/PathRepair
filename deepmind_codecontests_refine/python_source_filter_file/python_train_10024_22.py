n=int(input())
arr=list(map(int,input().split()))
max1=max(arr)
min1=min(arr)
mi=arr[::-1].index(min1)
ma=arr.index(max1)
if mi+ma>n:
    print(mi+ma-1)
else:
    print(mi+ma)