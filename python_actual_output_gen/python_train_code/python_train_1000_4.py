n=int(input())
array=list(map(int,input().split()))
array.sort()
b=1
for i in range(max(array)//min(array)+1):
  for j in range(1,n):
     if array[j]>array[0]:
          array[j]=array[j]-array[0]
          array.sort()

print(sum(array))