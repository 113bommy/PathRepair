a,b=map(int,input().split())
a1,a2,a3,b1,b2,b3=0,0,0,0,0,0
while a%2==0:
    a1+=1
    a=a//2
while a%3==0:
    a2+=1
    a=a//3
while a%5==0:
    a3+=1
    a=a//5
while b%2==0:
    b1+=1
    b=b//2
while b%3==0:
    b2+=1
    b=b//3
while b%5==0:
    b3+=1
    b=b//5
if a!=b:
    print(-1)
else:
    print(abs(a1-b1)+(a2-b2)+(a3-b3))