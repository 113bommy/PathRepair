x,a,b = map(int, input().split())
print("dalicious" if a-b > 0 else "safe" if b-a<=x else "dangerous")