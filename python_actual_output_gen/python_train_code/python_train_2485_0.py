size= int(input())
arr = list(map(int,input().split()))
count = m = 0
for i in range(size-1):
  if arr[i]+1 == arr[i+1]:
    if (i == 0 and arr[i] == 1) or (i == size-1 and arr[i+1] == 1000):
      count+=1
    count+=1
  else:
    count = 0  
  if m < count:
    m = count

if m == 0:
  print(0)
else:
  print(m-1)      
