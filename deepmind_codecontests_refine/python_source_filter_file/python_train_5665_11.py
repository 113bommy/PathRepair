n=int(input())
array=[]
a=0
b=0
c=0
for i in range(n):
 array.append(list(map(int, input().split())))
for i in range(n):
   a+=array[i][0]
   b+=array[i][1]
if a%2==0 and b%2==0:
   print("0")
elif n==1:
   print("-1")

elif (a%2==0 and b%2!=0 ) or (a%2!=0 and b%2==0):
   print("-1")
else :
   for i in range(n):
      if array[i][0]==array[i][1]:
         c+=1
   if c==n:
      print("-1")
   else:
      print("1")