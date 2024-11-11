n = int(input())
res = 0
for i in range(1,n+1):
  if(len(i)%2):
    res+=1
print(res)