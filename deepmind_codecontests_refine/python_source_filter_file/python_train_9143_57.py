
a,b,c,d = map(float, input().split())

a,b = max(a,c), min(b,d)

a = max(0.0, b-a)

print(a)
