N=int(input())
A=[int(input()) for i in range(N)]
x,r=0,0
for a in A:
    d=(a-1)//(x+1)
    if d==0:
        x=a
    elif x==0:
        x=1
    r+=d
print(r)