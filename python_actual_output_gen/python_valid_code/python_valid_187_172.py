x, b, r = map(int, input().split())
k=x/(b+r)
print(k*b+min(x%(b+r), b))