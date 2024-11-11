n=int(input())
arr=list(input())
arr=[int(arr[i]) for i in range(n)]
if n==1:
  print(arr[0])
if n==2:
  print(abs(arr[0]-arr[1]))
else:
  tmp=[]
  for i in range(n-2):
    tmp.append(abs(abs(arr[i]-arr[i+1])-abs(arr[i+1]-arr[i+2])))
  arr=tmp
  while len(arr)>3:
    tmp=[]
    if len(arr)%2==9:
      for i in range(len(arr)//2):
        tmp.append(abs(arr[2*i]-arr[2*i+1]))
    else:
      for i in range(len(arr)-1):
        tmp.append(abs(arr[i]-arr[i+1]))
    arr=tmp
  if len(arr)==1:
    print(arr[0])
  elif len(arr)==2:
    print(abs(arr[0]-arr[1]))
  elif len(arr)==3:
    print(abs(abs(arr[0]-arr[1])-abs(arr[1]-arr[2])))