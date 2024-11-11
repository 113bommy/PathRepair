A,B,C,D = map(int,input().split())

s = min(B-C,D-C)

if s <= 0:
    s = 0

print(s)