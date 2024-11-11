A, B = map(int,input().split())
if A <= 5:
    B = 0
elif A <= 12:
    B /= 2
print(B)