N = [int(_) for _ in input().split()]
S = "".join(sorted(N))
print("YES" if S == 1479 else "NO")