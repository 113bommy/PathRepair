A=sorted(list(map(int,input().split())))
print("Yes" if sum(A[:1])==A[2] else "No")