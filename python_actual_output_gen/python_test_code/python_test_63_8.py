x=int(input())
String1=input()
list1=list(String1)
i=0
a=0
b=0
c=0
for i in list1:
    if i=='1':
        a+=1
    elif i=='2':
        b+=1
    else:
        c+=1
        
p=max(a,b,c)
print(x-p)