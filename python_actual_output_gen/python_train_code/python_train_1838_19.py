n=int(input())

#1=2*4-1*7
#2=4*4-2*7
#3=6*4-3*7
#5=3*4-1*7
#6=5*4-2*7
l=[0,8,16,24,4,12,20]
flag=0
for i in range(6):
    if(n%7==i and n>=l[i]):
        n-=l[i]
        k=n//7
        p=l[i]//4
        flag=1
        break

if(flag==0):
    print(-1)
else:
    for i in range(p):
        print(4,end="")
    for i in range(k):
        print(7,end="")
