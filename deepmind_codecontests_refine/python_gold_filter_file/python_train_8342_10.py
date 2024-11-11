def func(arr):
  count=0
  biggest=-1
  store=[]
  for x in range(len(arr)):
    if arr[x][0]>biggest:
      store.append(arr[x])
      biggest=arr[x][1]
      count+=1
  return count,store
def main():
  n=int(input())
  arr=input().split()
  store=[]
  for x in range(n):
    arr[x]=int(arr[x])
    total=0
    for y in range(x,-1,-1):
      total+=arr[y]
      bo=True
      for z in range(len(store)):
        if total==store[z][0]:
          bo=False
          store[z][1].append((y,x))
      if bo:
        store.append([total,[(y,x)]])
  #print(store)
  biggest=0
  big_val=[]
  for  x in range(len(store)):
    test,test_s=func(store[x][1])
    if test>biggest:
      biggest=test
      big_val=test_s
  print(biggest)
  for x in range(len(big_val)):
    print(big_val[x][0]+1,big_val[x][1]+1)
  
main()
