l=list(map(int,input().split()))
n=l[0]
m=l[1]
g=list(map(str,input().split()))
h=list(map(str,input().split()))
t=int(input())
for i in range(t):
    a=int(input())
    b=g[a%n]
    c=h[a%m]
    print(b+c)
