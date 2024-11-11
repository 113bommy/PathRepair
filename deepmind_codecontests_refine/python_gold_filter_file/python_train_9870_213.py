a,b = list(map(int, input().split()))
print(b if a>=13 else b//2 if a>5 else 0)