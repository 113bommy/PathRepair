
n=int(input())
a=[]
b=[]
for i in range(n):
    tmpa,tmpb = map(int,input().split())
    a.append(tmpa)
    b.append(tmpb)

a.sort()
b.sort()

if n%2==1:
    print(b[n//2] - a[n//2] +1)
else:
    print((b[n//2]+b[n//2-1]) - (a[n//2]+a[n//2-1]) +1)
