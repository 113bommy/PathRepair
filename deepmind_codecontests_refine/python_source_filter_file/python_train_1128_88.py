n=int(input())
A=list(map(int,input().split()))
A=[a for a in A if a<3200]
free=n-len(A)
A=set(map(lambda x: x//400,A))
print(len(A),len(A)+free)