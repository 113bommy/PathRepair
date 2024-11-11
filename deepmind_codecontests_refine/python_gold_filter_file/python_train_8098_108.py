a=int(input())
ans=-1
for i in range(a+1):
  if len(str(i))%2 == 1:
    ans+=1

print(ans)