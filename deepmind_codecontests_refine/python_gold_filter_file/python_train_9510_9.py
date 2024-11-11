# https://codeforces.com/problemset/problem/205/A

n = input()
l = []
mini = 10**9
ind = 1
i=1
for x in input().split():
    x = int(x)
    l += [x]
    if x < mini:
        mini = x
        ind = i
    i += 1

print(ind if l.count(mini) == 1 else 'Still Rozdil')
