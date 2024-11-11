n=int(input())
Ans=""
A=[0,0]
B=[0,0]
for i in range(n):
    l,x,y=map(int,input().split())
    if(l==1):
        A[0]+=x
        A[1]+=10
    else:
        B[0]+=x
        B[1]+=10
if(A[0]/A[1]>=1/2):
    print("ALIVE")
else:
    print("DEAD")

if(B[0]/B[1]>=1/2):
    print("ALIVE")
else:
    print("DEAD")
