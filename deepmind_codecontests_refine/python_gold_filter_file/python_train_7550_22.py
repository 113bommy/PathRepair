n=int(input())
print(n - len(set(input())) if n <= 26 else -1)
