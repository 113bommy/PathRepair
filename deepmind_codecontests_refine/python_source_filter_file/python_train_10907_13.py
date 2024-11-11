x, k, d = map(int, input().split())
t = abs(x)//d
if k*d <= abs(x):
    print(abs(x) - k*d)
else:
    print(abs(d*(max(0, k-t)%2) - (x-t*d)))
