from sys import stdin, stdout
input = stdin.readline

n, m = map(int, input().split())
s = list(input())
f = 0
ans = []

for i in range(1,n):
    if s[i] == s[i-1] and s[i] == '.':
        f+= 1

for i in range(m):
    x, ch = input().split()
    x = int(x) - 1

    if s[x] != ch and s[x] == '.' or ch == '.': # could be different letter but not a dot
        if ch == '.':
            if x > 0 and s[x-1] == '.':
                f += 1
            if x < n - 1 and s[x+1] == '.':
                f += 1
        else:
            if x > 0 and s[x-1] == '.':
                f -= 1
            if x < n - 1 and s[x+1] == '.':
                f -= 1
        s[x] = ch
    ans.append(f)

stdout.write("\n".join(map(str,ans)))
