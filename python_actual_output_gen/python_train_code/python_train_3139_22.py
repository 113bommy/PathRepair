A,B,C,D = map(int,input().split())

s = max(A,C)-min(B,D)

if s <= 0:
    s = 0

print(s)