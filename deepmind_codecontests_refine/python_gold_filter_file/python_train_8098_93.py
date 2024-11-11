n=int(input())
re=0
for i in range(1,n+1):
  if len(str(i))%2==1:
    re+=1
print(re)