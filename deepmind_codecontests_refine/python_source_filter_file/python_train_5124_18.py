sum=0
for i in range(int(input())):
 k=int(input())
 li=input()
 for i in li:
  ki=li
  li=li.replace("AP","A")
  if ki!=li:
   sum+=1
print(sum)