N=input()
c=0
flag = 0
for i in N:
    if i=='C' and  c==0 :c+=1
    if i=='F' and c==1: flag=1
if flag:print("Yes")
else flag:print("No")