name = input()
n = int(input())
d = dict()
action = [' likes ', ' commented on ', ' posted on ' ]
for _ in range(n):
    s = input()
    for i in range(3):
        if action[i] in s:
            s = s.split(action[i])
            break
    a, b = s
    b = b.split('\'')[0]
    s = [a, b]
    if name in s:
        a = s[1-s.index(name)]
        d[a] = d.get(a,0) - (i+1)*5
    else:
        d[a] = d.get(a,0)
        d[b] = d.get(b,0)
ans = [[d[i], i] for i in d]
ans.sort(key = lambda x: (-x[0], x[1]))
for i in ans:
    print(i[1])
