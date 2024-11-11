n=int(input())
a=list(map(int,input().split()))
M=max(a);m=min(a)
s=0
for i in range(n):
    if s==0 and a[i]==M:
        s=i
    elif a[i]==m:
        t=i
if s<t:
    print(s+n-1-t)
else:
    print(s+n-2-t)
