n = int(input())
x = list(sorted(map(int, input().split()), reverse=True))
if n % 2:
    b = sum(x[:n//2+1])
    c = sum(x[n // 2 + 1:])
else:
    b = sum(x[:n//2])
    c = sum(x[n//2:])
print(b*b + c*c)
