k=int(input())
n=input()
arr=[]
for i in n:
  arr.append(int(i))
arr.sort()
summ=sum(arr)
count=0
if summ<k:
  for i in arr:
    summ+=10-i
    count+=1
    if summ>=k:
      break
  print(count)
else:
  print(0)