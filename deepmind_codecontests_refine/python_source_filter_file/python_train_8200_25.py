N=int(input())
A=list(map(int,input().split()))
print(['No','Yes'][int(len(set(A))==len(A))])