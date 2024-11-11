A,B = map(int, input().split())
print(B if A>=13 else int(B/2) if A>=6 else 0)