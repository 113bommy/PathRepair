N, A, B = map(int, input().split())
print("Alice" if (B - A) % 2 == 1 else "Borys")