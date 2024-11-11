n,k = list(map(int,input().split()))
arr = list(map(int,input().split()))

score = 0
x=0
flag = False

while score!=k:
  # print("Comparing:", arr[x], "&", arr[x+1])

  if arr[x] > arr[x+1]:
    arr.append(arr[x+1])
    arr.pop(x+1)
    score += 1
    if flag==True:
      score += 1
    if(arr[x] == max(arr)):
      break

    flag = False
  
  else:
    score = 0
    flag = True
    arr.append(arr[x])
    arr.pop(x)

  print(arr)

print(arr[x])
