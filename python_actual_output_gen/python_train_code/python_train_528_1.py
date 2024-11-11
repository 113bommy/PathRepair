rdi = lambda: list(map(int, input().split()))

def f(x): return x if x<10 else x/10+9-(0 if str(x)[0]<=str(x)[-1] else 1)

l, r = rdi()
print(f(r)-f(l-1))