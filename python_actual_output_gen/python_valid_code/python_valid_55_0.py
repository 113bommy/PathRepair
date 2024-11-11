n,k,x =list(map(int ,input().split()))
arr = list(map(int ,input().split()))
arr.sort()
groups =1
re = []
for i in range(n-1):
    diff = arr[i+1]-arr[i]
    if diff>x :

      if k==0:
        groups+=1
        continue
      if diff%k==0:
        diff = diff//k -1
      else:
        diff =diff//k
      re.append(diff)
      groups+=1
re.sort()
for i in range(len(re)):
    k-=re[i]
    if k>=0:
      groups-=1
    else:
      break

print(groups)    