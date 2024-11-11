import sys
input = sys.stdin.readline

X,Y,Z,K=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

AB=[]
for a in A:
    for b in B:
        AB.append(a+b)

AB.sort(reverse=True)
AB=AB[:K]

ALL=[]

for ab in AB:
    for c in C:
        ALL.append(ab+c)

ALL.sort(reverse=True)

for k in range(K):
    print(ALL[k])
