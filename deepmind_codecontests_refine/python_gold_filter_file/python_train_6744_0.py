N=int(input())
A=list(map(int,input().split()))

b=[0]*N
for c in A:
    b[c-1]+=1

for i in b:
    print(i)