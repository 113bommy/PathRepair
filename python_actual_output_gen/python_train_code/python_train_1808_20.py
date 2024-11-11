n = int(input())
s = input()

ans = [0 for _ in range(n)]

for i in range(n):
    if s[i] == 'L':
        for j in range(n):
            if ans[j] == 0:
                ans[j] = 1
                break
    elif s[i] == 'R':
        for j in reversed(range(n)):
            if ans[j] == 0:
                ans[j] = 1
                break
    else:
        ans[int(s[i])] = 0

print(''.join(map(str, ans)))
