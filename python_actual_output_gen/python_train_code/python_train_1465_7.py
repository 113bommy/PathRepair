d, k, a, b, t = [int(i) for i in input().split()]
if k >= d:
    print(k * a)
elif t + k * a >= k * b:
    print(d * b + k * a - k * b)
else:
    x = d // k;
    print(x * k * a + t * (x - 1) + min((d - k * x) * b, t + (d - k * x) * a))