A = list(map(int, input().split()))
if A == list(set(A)):
    print("Yes")
else:
    print("No")
