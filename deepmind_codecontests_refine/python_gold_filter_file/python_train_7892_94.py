A=list(map(int,input().split()))
K=int(input())
B=sorted(A)
print(B[0]+B[1]+B[2]*2**K)