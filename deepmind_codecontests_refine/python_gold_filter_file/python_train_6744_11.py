N=int(input())
A=list(map(int,input().split()))
S=[0]*N
for i in A:
    S[i-1]+=1
for i in S:
    print(i)