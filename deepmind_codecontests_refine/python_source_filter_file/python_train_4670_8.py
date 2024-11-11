import sys
input=sys.stdin.readline

N,M=map(int,input().split())

R=[1 for i in range(N+1)]
A,B=map(int,input().split())
R[A]=0
R[B]=0

L=[[]for i in range(N+1)]
L[A].append(B)
L[B].append(A)

for i in range(M-1):
    a,b=map(int,input().split())
    L[a].append(b)
    L[b].append(a)

l=[A]
P=A
#print(L)

for i in range(10**6):
    flag=0
    #print("P",L[P])
    for j in L[P]:
        #print("j",L,L[P],j,P)
        if R[j]==1:
            P=j
            R[j]=0
            l.append(j)
            flag+=1
            break
    if flag==0:
        break
#print(l)
r=[B]
P=B
for i in range(10**6):
    flag=0
    #print("P",L[P])
    for j in L[P]:
        #print("j",L,L[P],j,P)
        if R[j]==1:
            P=j
            R[j]=0
            r.append(j)
            flag+=1
            break
    if flag==0:
        break
#print(r)
l=l[::-1]
ans=l+r

ANS=str(ans[0])
for i in range(1,len(ans)):
    ANS+=" "+str(ans[i])
print(len(ans))
print(ANS)