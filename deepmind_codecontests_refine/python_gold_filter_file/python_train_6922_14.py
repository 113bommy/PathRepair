from bisect import bisect_left
n,m=list(map(int,input().split()))
k,m=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
i=bisect_left(a,b[-m])
if(i>=k):
    print("YES")
else:
    print("NO")