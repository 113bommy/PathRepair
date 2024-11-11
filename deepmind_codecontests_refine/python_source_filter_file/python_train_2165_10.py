n=int(input())
a=map(int,input().split())
i=1
for k in a:
  if k==i: i+=1
1-=1
print(N-i if i>0 else -1)