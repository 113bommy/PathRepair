A = list(map(int, input().split()))
if A == list(set(A)):
    print("YES")
else:
    print("NO")
