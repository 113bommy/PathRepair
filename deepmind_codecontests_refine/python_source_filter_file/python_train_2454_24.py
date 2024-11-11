a=int(input())
b=int(input())
c=int(input())
a2=a; b2=0; c2=0
for i in range(a,-1,-1):
    if b//2!=0 and c//4!=0:
        b2+=2; c2+=4; a2-=1
        b-=2; c-=4
result=b2+c2+(a-a2)
print(result)













