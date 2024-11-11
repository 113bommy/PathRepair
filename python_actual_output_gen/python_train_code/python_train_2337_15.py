N=int(input())
A=list(map(int, input().split()))
b=[0]*N
for i in A:
    b[i-1]+=1
for i in b:
    print(b)