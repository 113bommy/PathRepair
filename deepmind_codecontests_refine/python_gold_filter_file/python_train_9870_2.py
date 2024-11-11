A, B = map(int, input().split())
print(B if A>=13 else B//2 if 6<=A<13 else 0)