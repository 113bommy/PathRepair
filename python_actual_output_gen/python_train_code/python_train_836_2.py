n=int(input())
l=list(map(int,input().split()))
ans=0
for a in l:
  for b in l:
    for c in l:
      if (a==b or b==c or a==c):
        continue
      if max([a,b,c])<a+b+c-max([a,b,c]):
        ans+=1
print(ans)