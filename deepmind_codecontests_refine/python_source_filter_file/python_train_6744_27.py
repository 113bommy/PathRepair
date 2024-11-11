N = int(input())
X = [0]*N
A = list(map(int,input().split()))
for i in A:
    X[i] +=1
print(*X,sep="\n")