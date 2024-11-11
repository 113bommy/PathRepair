n,h,m=map(int, input().split())
height=[h]*n
for _ in range(m):
 a,b,c=map(int, input().split())
 for i in range(a-1,b):
  height[i]=min(height[i],c)
print(sum(i**2 for i in height))