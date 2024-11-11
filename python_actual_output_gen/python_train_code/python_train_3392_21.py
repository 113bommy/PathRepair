n = eval(input())
s = input().split()
maxn = max(map(eval,s))
s = list(map(lambda x: maxn-eval(x),s))
ans = 0
for i in s:
    ans += s[i]
print(int(ans))