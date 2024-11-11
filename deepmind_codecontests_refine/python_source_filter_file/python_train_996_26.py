import math
#t=int(input())
#for i in range(t):
a,b = map(int, input().strip().split(' '))
c,d = map(int, input().strip().split(' '))
f=0
k=0
if a%2==0 and b%2==0 and c%2==0 and d%2!=0:
    print(-1)
elif c%2==0 and d%2==0 and a%2==0 and b%2!=0:
    print(-1)
else:
    for i in range(1,101):
        for j in range(1,101):
            k=i*a - j*c
            if k==d-b:
                f=1
                print(b+(i)*a)
                break
        if f==1:
            break
    if f==0:
        print(-1)






#n=int(input())
#lst = list(map(int, input().strip().split(' ')))

               
