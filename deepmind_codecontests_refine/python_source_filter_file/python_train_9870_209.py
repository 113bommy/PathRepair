A, B = map(int, input().split())
print(0 if B < 6 else B//2 if B < 13 else B)