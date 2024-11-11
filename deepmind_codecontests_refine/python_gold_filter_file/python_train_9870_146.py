A,B=[int(a) for a in input().split()]
print(B if A>=13 else (0 if A<=5 else B//2))