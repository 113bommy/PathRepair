A, B, C, D = map(str, input().split())
L=A+B
R=C+D
print("left" if R < L else "right" if R > L else "Balanced")