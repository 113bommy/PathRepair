n = int(input())
s = input()
a = s[n - 3::n]
b = s[n - 2::n]
c = s[n - 1::n]
print(sum(x == y == z for x, y, z in zip(a, b, c)))
