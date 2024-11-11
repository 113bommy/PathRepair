A,B = map(int,input().split())
print(B if A >= 13 else B // 2 if A >= 12 else 0)