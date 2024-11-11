arr=list(map(int,input().split()))
s=0
for i in range(1,4):
  for j in range(2):
    if arr[j]==i:
      s+=(4-i)*100000
if arr[0]==arr[1] and arr[1]=1:
  s+=400000
print(s)
  
