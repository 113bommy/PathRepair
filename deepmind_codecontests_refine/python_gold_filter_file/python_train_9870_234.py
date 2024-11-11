A, B = map(int, input().split())
print(B if A > 12 else B//2 if A > 5 else 0)