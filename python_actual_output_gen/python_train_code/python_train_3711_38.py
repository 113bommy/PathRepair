A, B, C, D = [int(x) for x in input().split()]
print("Yes" if abs(A-C) <= 3 or (abs(A-B)<=3 and abs(B-C)<=3) else "No")