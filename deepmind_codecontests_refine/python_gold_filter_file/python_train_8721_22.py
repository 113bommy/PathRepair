N, M = map(int, input().split())
A = list(map(int, input().split()))
B = [x for x in A if x >= sum(A)/(4*M)]
print("Yes" if len(B) >= M else "No")