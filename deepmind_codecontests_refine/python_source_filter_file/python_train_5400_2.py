def f(x):return 1if x<2else x*f(x-1)
print(f(int(input())))