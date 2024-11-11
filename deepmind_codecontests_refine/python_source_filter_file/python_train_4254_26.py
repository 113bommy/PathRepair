# coding: utf-8
N,M=map(int,input().split())
NL=[0 for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    NL[a-1]+=1
    NL[b-1]+=1

flg=True

for i in range(N):
    if NL[i]%2==1:
        flg=False

if flg:
    print("Yes")
else:
    print("No")
