N=int(input())//2
A=sorted(a-i-1 for i,a in enumerate(map(int,input().split())))
print(sum(abs(a-A[N])for a in A))