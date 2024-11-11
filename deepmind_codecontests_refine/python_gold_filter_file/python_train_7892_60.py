A,B,C=map(int,input().split())
k=int(input())
m=max(A,B,C)
print(A+B+C-m+m*2**k)
