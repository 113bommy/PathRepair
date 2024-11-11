size=int(input())
arr = list(map(int, input().split()))
i=0
while i<size-1 and arr[i]>arr[i+1]:
     i+=1
while i<size-1 and arr[i]==arr[i+1]:
     i+=1
while i<size-1 and arr[i]<arr[i+1]:
    i+=1
if i<size-1:
   print ("NO")
else:
   print ("YES")


