n,l=map(int,input().split())
x=list(map(int,input().split()))
x=sorted(x)
maxx=max(x[0]-0,x[n-1]-l)*2
for i in range(n-1,0,-1):
     t=x[i]-x[i-1]
     if t>maxx:
          maxx=t
print(maxx/2)

