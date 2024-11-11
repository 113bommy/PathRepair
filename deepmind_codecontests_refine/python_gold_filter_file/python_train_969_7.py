n=int(input())
a=[int(i) for i in input().split()]
s=0
if n==1:
    print(0)
    raise SystemExit
for i in range(1,n):
    if a[i]>max(a[0:i]) or a[i]<min(a[0:i]):
        s=s+1
print(s)
