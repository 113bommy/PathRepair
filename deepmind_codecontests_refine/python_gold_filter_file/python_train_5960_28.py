n,m,k = (int(x) for x in input().split())
start = []
goal = []
for i in range(k):
    start.append([int(x) for x in input().split()])
for i in range(k):
    goal.append([int(x) for x in input().split()])

if n > 1 and m > 1:
    ans = (n-1)*'U' + (m-1)*'L'
    for i in range(n):
        if i % 2 == 0:
            ans += (m-1)*'R' + 'D'
        else:
            ans += (m-1)*'L' + 'D'
    ans = ans[:-1]
elif n == 1 and m == 1:
    ans = 'U'
elif n == 1:
    ans = (m-1)*'L' + (m-1)*'R'
elif m == 1:
    ans = (n-1)*'U' + (n-1)*'D'
print(len(ans))
print(ans)