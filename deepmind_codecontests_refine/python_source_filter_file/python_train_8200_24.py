N=int(input())
A=list(map(int,input().split()))
print(['No','Yes'][(len(set(A))==len(A))])