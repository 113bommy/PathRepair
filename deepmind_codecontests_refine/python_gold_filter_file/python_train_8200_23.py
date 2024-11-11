N=int(input())
A=list(map(int,input().split()))
print(['NO','YES'][int(len(set(A))==len(A))])