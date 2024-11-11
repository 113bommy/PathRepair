n,k=map(int,input().split())
a=list(map(int,input().split()))
a=list(set(a))
a=sorted(a)
n=len(a)
s=0
if n>=k:
    for i in range(k):
        print(a[0]-s)
        s=s+a[0]
        a.pop(0)
else:
    for i in range(n):
        print(a[0]-s)
        s=s+a[0]
        a.pop(0)
    for i in range(k-n):
        print(0)