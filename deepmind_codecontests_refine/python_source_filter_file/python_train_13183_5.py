from sys import stdin, stdout

a = int(stdin.readline())
b = int(stdin.readline())

ans = ''

c = sorted(list(str(a)))

while c:
    for i in range(len(c) - 1, -1, -1):
        if int(''.join(list(ans) + [c[i]] + c[:i] + c[i + 1:])) < b:
            ans += c[i]
            c.pop(i)
            break

stdout.write(ans)