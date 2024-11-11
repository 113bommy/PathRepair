A, B, C, D = map(int, input().split())
L=A+B
R=C+D
print("Left" if R < L else "Right" if R > L else "Balanced")