count=0
n=int(input())
for i in range(1,n+1):
  if len(str(i))%2==1:
    count+=1
print(count)
