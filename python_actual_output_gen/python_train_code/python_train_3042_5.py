N=int(input())
A=sorted(a-i-1 for i,a in enumerate(map(int,input().split())))
print(sume(abs(a-A[N//2]) for a in A))