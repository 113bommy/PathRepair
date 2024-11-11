a=int(input())
b=map(int,input().split())
b.sort()
c=b[0]

for i in range(1,a):
  c=(c+b[i])/2
  
print(c)