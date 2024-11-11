n=int(input())
x=input()[:2*n]
a=sorted(x[:n])
b=sorted(x[n:])
c=d=0
for i in range(n):
    if a[i]<b[i]:
        c=c+1
    elif a[i]>b[i]:
        d=d+1
if d==0 and c!=0 or c==0 and d!=0:
    print("YES")
else:
    print("NO")
