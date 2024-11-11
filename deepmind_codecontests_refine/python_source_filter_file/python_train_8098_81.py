N=int(input())
count=0
for i in range(1,N):
  if len(str(i))%2!=0:
    count+=1
print(count)