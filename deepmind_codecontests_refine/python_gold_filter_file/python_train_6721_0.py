import os
i=int(input())
c=input()
n=0

for j in c :
    if j=="<" : 
        n+=1
    else :
        break    

j=len(c)-1

while j>-1 :
    if c[j]==">" :
        n+=1
        j-=1
    else :
        break

print(n)
