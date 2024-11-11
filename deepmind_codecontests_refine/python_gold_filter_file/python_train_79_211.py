A,B = map(int, input().split())
print(A*B if max(A,B) <= 9 else -1)