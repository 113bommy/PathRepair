n=input()
n1=int(input())
li=[]
for i in range(n1):
 li.append(input())
flag1=0
flag=0
if n in li:
 print("YES")
 exit(0)
for i in range(n1):
 if n[0] == li[i][1]:
  flag=1
  break
for j in range(n1):
 if n[1] == li[j][0]:
  flag1=1
  break
if flag1==1 and flag==1:
 print("YES")
else:
 print("NO")