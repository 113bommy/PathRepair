n=int(input())
A=list(map(int,input().split()))
N=[0]*(n)
for i in A:
    N[i-1]+=1
for i in N:
    print(i)