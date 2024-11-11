k=int(input())
sevs=7
for x in range(1,k+1):
  if sevs%k==0:
    print(x)
    exit()
  else:
    sev=(10*sevs+7)%k
print('-1')
    