N=int(input())
a=[]
b=[]
for _ in range(N):
    A,B=map(int,input().split())
    a.append(A)
    b.append(B)
a=sorted(a)
b=sorted(b)
if N%2==1:
    print(b[N//2]-a[N//2]+1)
else:
    print(int(((b[N//2-1]+b[N//2])/2-(a[N//2-1]+a[N//2])/2)*2+1))