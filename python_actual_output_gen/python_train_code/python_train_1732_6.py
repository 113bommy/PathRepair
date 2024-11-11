n=int(input())
s=input()
a,b=0,0
for chr in s:
    if chr =='(':
        a+=1
    else:
        a-=1
        if a<0:
            b+=2
if a!=0:
    b-=1
print(b)