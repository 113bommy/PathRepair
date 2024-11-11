input()
s=input()
l='('
r=')'
d=0
a=[]
pre=0
for i in s:
    if i==l:
        if pre==l:
            d+=1
        pre=l
    else:
        if pre==r:
            d-=1
        pre=r
    
    if d%2==0:
        a+=[1]
    else:
        a+=[0]
#print(s)
for i in a:
    print(i,end='')