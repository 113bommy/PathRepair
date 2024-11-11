n=int(input())
l=list(input())
a=0
b=0
c=0
d=0
for  i in range(n//2):
    if l[i]=='?':
        a+=1
    else:
        c+=int(l[i])
for i in range(n//2,n):
    if l[i]=='?':
        b+=1
    else:
        d+=int(l[i])
x=a//2
if a%2:
    x+=1
y=b//2
if b%2:
    y+=1
if a*9+c>b*9+d or (a-x)*9+c<(b-y)*9+d:
    print("Monocarp")
else:
    print("Bicarp")
    
    

    
