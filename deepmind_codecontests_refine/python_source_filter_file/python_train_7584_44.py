s = {}
s['a'] = list(input())
s['b'] = list(input())
s['c'] = list(input())

now = 'a'
while s[now]:
    now = s[now].pop()
print(now.upper())