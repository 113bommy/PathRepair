def f(z):
    return sum(int(i) for i in z)


x = input()
k = len(x)
m = f(x)
ans = -1
for i in range(1, k + 1):
    a = int(x[:i])
    b = x[i:]
    if not all(j == "9" for j in b):
        a -= 1
    b = "9" * len(b)
    w = str(a) + b
    if f(w) >= m:
        m = f(w)
        ans = str(a) + b
print(int(ans))
