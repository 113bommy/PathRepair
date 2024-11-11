n=input()
ls=input().split()
a=1
m=0
for i in range(int(n)-1):
    
    if int(ls[i])<=int(ls[i+1]):
        a+=1
    elif int(ls[i])>int(ls[i+1]):
        a=1

    
    
    if a>m:m=a

print(m)
