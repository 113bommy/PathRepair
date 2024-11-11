n=int(input())
a=[]
b=[]
for _ in range(n):
  x,y=map(int,input().split())
  a+=[abs(x-y)]
  b+=[x+y]
a.sort()
b.sort()
print(max(a[-1]-a[0],b[-1]-b[0]))