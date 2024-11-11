n = int(input())
s = input()
a = s[n - 3:-1:n]
b = s[n - 2:-1:n]
c = s[n - 1:-1:n]
print(sum(x == y == z for x, y, z in zip(a, b, c)))
