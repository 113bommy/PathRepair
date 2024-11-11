
#n=int(input())
n,m=map(int,input().split())

a=list(map(int,input().split()))

b=list(map(int,input().split()))

a.sort()

x=max(a[0]*b[m-1],a[0]*b[0],a[n-2]*b[m-1],a[n-2]*b[0])
y=max(a[1]*b[m-1],a[1]*b[0],a[n-1]*b[m-1],a[n-1]*b[0])

print(min(x,y))


