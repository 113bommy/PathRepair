N=int(input())
A=sorted(map(int,input().split()))
print(sum(A[::2])*2-sum(A))