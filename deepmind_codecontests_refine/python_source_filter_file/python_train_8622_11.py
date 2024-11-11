import math

q=int(input())
N=[0]*(10**5+1)
N[3]=1
N[2]=1
S=[]

for i in range(5,10**5+1,2):
    flag=True
    for j in range(3,int(math.sqrt(i))+1,2):
        if i%j==0:
            flag=False
            break
    if flag:
        N[i]=1

X=[0]*(10**5+1)
X[2]=1
cnt=0
for i in range(3,10**5+1,2):
    if N[i]==1 and N[(i+1)//2]==1:
        cnt+=1
    X[i]=cnt
Q=[]
for i in range(q):
    l,r=map(int,input().split())
    print(X[l]-X[r-2])