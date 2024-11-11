n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
b=a[::-1]
if b[m-1]<sum(a)/(4*m):
    print("No")
elif True:
    print("Yes")