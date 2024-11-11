n = int(input())
a=[]
for i in range(n):
  x,y=map(int,input().split())
  a.append([x,y])
ans=0
a=a[::-1]
for i,j in a:
  ans+=j- (i+ans)%j if (i+ans)%j else j
print(ans)