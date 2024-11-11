A, B, C = map(int, input().split())
print(["A", "B"][abs(A-B) < abs(B-C)])