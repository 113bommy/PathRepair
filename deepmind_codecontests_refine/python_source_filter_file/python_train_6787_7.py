n, m = map(int, input().split())
modulo = 10 * 9 + 7
combs = 0
r = 1
r_next = 2
for i in range(3, n + 1):
    r, r_next = r_next, (r + r_next) % modulo
combs += r_next if n > 1 else 1
c = 1
c_next = 2
for j in range(3, m + 1):
    c, c_next = c_next, (c + c_next) % modulo
combs += c_next if m > 1 else 1
combs -= 1
combs *= 2
print(combs % modulo)