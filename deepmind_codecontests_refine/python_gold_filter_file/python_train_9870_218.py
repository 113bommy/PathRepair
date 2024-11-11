A,B=map(int, input().split())

print(B if A >= 13 else 0 if A <= 5 else int(B/2))