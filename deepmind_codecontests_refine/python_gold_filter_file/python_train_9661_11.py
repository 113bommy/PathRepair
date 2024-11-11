N=int(input())
listA=list(map(int,input().split()))
listB=[abs(i) for i in listA]
MAX=max(listA)
MIN=min(listA)
ans=sum(listB)
if MAX<=0:
  print(ans+MAX*2)
elif MIN<=0:
  print(ans)   
else:
  print(ans-MIN*2)
listC=sorted(listA)  
for i in range(len(listA)-2):
  if listC[i+1]>=0:
    print(MIN,listC[i+1])
    MIN=MIN-listC[i+1]
  else:
    print(MAX,listC[i+1])
    MAX=MAX-listC[i+1]
print(MAX,MIN)