A=list(map(int,input().split()))
A.sort()
print(["Yes","No"][A[0]+A[1]!=A[2]])
