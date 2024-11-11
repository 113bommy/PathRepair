x=int(input())
c=(x//11)*2
a=x%11
if a<=5 and a!=0:c+=1
elif a<11 and a!=0:c+=2
print(c)
