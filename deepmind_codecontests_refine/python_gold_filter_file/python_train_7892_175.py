A,B,C=map(int,input().split())
K=int(input())

m=max(A,B,C)
print((2**K)*m + (A+B+C-m))