N=int(input())
S=input()
l=0
a=1
for i in range(2*N):
    if S[i]=="W":
        if l%2==0:
            a=a*l%(10**9+7)
            l-=1
        else:
            l+=1
    else:
        if l%2==0:
            l+=1
        else:
            a=a*l%(10**9+7)
            l-=1
if l!=1:
    a=0
for i in range(1,N+1):
    a=a*i%(10**9+7)
print(a)