a=int(input())
b=int(input())
c=int(input())
q=int(input())
ans=0
for i in range(a+1):
  for i in range(b+1):
    for i in range(c+1):
      if 500*a+100*b+50*c==q:
        ans+=1
print(ans)
