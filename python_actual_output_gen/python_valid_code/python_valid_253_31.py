n=int(input())
mas=[]

pos=False
for i in range(n):
  x=input()
  if pos==False:
    if x[:2]=="OO":
         pos=True
         x="++"+x[2:]
         mas.append(x)
         continue
    elif x[3:]=="OO":
         pos=True
         x=x[:2]+"++"
         mas.append(x)
    else:
       mas.append(x)          
  else:
       mas.append(x)
if pos==False:
	print("NO")
else:
    print("YES")
    for i in range(n):
       print(mas[i])	