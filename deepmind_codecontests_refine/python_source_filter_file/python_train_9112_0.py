n, k = map(int, input().split())
A = list(map(int, input().split()))

def f(x):
    over = 0
    need = 0
    for a in A:
        if a > x:
            over += (a - x)
        else:
            need += (x - a)
    return need <= (over * (k/100))

left = 0
right = 1000
while right - left > 1e-12:
    m = (left + right) / 2
    if f(m):
        left = m
    else:
        right = m

print(right)