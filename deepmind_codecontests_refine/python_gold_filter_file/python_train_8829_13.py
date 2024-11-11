n=int(input())
A=sorted(a-i-1 for i,a in enumerate(map(int,input().split())))
print(sum(abs(a-A[n//2])for a in A))