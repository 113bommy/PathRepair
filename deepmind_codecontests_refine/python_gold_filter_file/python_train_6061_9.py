# https://codeforces.com/contest/1295/problem/A

num = int(input())
out = []

# 0 6
# 1 2
# 2 5
# 3 5
# 4 4
# 5 5
# 6 6
# 7 3
# 8 7
# 9 6

# 1 2
# 7 3
# 4 4
# 5 5
# 9 6
# 8 7

for i in range(num):
    n = int(input())

    s = ''

    while True:
        if n - 2 >= 2:
            n -= 2
            s += '1'
        elif n == 3:
            n -= 3
            s = '7' + s
        elif n == 2:
            n -= 2
            s += '1'

        if n == 0:
            break

    out.append(s)

for line in out:
    print(line)