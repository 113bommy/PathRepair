def f(x):
    return x-(x-2)//2

t = int(input())
while t > 0:
    t-=1
    n = int(input())
    print(f(n))
