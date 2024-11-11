N, A, B, C, D = map(lambda  x: int(x) - 1, input().split())
S = input()
if C < D:
    if "**" in S[A: D + 1]:
        print("No")
    else:
        print("Yes")
else:
    if "**" in S[A: D + 1] or not("..." in S[B - 1: D + 2]):
        print("No")
    else:
        print("Yes")