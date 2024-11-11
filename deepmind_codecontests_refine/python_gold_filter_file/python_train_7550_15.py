n=int(input())
print(n-len(set(input())) if n<27 else -1)