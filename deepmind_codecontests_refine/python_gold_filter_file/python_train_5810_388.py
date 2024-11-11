A, B = map(int, input().split())
print((A + B) // 2 if not (A + B) % 2 else "IMPOSSIBLE")