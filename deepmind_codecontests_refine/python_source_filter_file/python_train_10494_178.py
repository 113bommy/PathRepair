N, A, B, C, D = [int(_) for _ in input().split()]
S = input()

if "##" in S[A-1:C] or "##" in S[B-1:D]:
    print("No")
elif C < D:
    print("Yes")
elif "..." in S[B-1:D]:
    print("Yes")
else:
    print("No")
