n,m=map(int,input().split())
a=0
b=float('inf')
for i in range(m):
      c,d=map(int,input().spilt())
      a=max(a,c)
      b=min(b,d)
print(max(0,b-a+1))
