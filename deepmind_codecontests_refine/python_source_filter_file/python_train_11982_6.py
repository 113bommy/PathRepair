s = list(input())
for i in range(len(s)):
    s[i] = int(s[i])
n = len(s)
ans = [i for i in s if i == 0 or i == 2]
c1 = sum([1 for i in s if i == 1])
f2 = 0
for i in range(len(ans)):
    if ans[i] == 2:
        f2 = i
        break
ans1 = ans[:i] +[1 for i in range(c1)] + ans[i:]
print(''.join([str(i) for i in ans1]))