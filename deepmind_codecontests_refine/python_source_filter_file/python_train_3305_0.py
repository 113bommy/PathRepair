import math
n=int(input())
l=list(map(int,input().split()))
mini=-1
ministep=-1
for i in range(n):
  #print(i,l[i]-i)
  if(l[i]-i>0):
    step=math.ceil((l[i]-i)/(n-1))
    print(i,step,l[i]-i)
    if(i==0):
      mini=i
      ministep=step
    elif(ministep>step):
      mini=i
      ministep=step
  else:
    mini=i
    break
print(mini+1)