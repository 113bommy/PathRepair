a,b = map(int, input().split())
print(b if a>12 else int(b/2) if a>5 else  0)