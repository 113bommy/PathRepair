def kiany(n, s):
    zeros, ones = s.count('0'), s.count('1')
    if zeros != ones:
        return 1, s
    return 2, s[0], s[:n - 1]


m = int(input())
t = input()
z = kiany(m, t)
x = len(z)
if x == 2:
    print(z[0])
    print(z[1])
if x == 3:
    print(z[0])
    print(z[1], z[2])
