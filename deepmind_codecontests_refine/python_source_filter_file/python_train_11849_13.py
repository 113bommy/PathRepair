N = int(input())
S = input()
a = 1
for c in [chr(i) for i in range(97, 123)]:
    a = (a * (S.count(c) + 1)) % (1e9 + 7)
print((a - 1) % (1e9 + 7))
