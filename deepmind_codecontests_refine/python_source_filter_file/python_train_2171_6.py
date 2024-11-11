a,b,c=map(int,input().split())
if a==b==c:print(-1);exit()
i=0
while a%2==0 and b%2==0 and c%2==0:
  aa=b//2+c//2
  bb=a//2+c//2
  cc=a//2+b//2
  a,b,c=aa,bb,cc
  i+=1
print(i)