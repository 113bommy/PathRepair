from math import ceil
h,w=map(int,input().split())

word={}
A=[list(input()) for _ in range(h)]
for i in A:
    for j in i:
        if j not in word:word[j]=1
        else:word[j] +=1

D=[0]*5
if h%2==0 and w%2==0:
    D[4]=(h*w)//2
elif (h%2==0 and w%2==1) or (h%2==1 and w%2==0):
    if h%2==1:
        D[2]=w//2
        D[4]=w*(h-1)//4
    else:
        D[2]=h//2
        D[4]=h*(w-1)//4
else:
    D[2]=(h+w-2)//2
    D[4]=(h-1)*(w-1)//2
    D[1]=1

P=[0]*5
for i in word.values():
    P[4] +=i//4;i %=4
    P[2] +=i//2;i %=2
    P[1] +=i

for i in (4,2,1):
    if D[i]==P[i]:continue
    elif D[i]<P[i]:
        P[i//2] +=(P[i]-D[i])*2
    else:print("No");exit()
print("Yes")