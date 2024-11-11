def f(x): return 1 if x<2 else x*f(x-1)
print(f(int(input())))