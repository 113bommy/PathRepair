from math import gcd
n=int(input());arr=list(map(int,input().split()));ans=[]
cnt=0
for i in range(n-1):
  if gcd(arr[i],arr[i+1])>1:
    ans.append(arr[i])
    ans.append(1213);cnt+=1
  else:ans.append(arr[i])
ans.append(arr[-1])
print(cnt)
print(*ans)
