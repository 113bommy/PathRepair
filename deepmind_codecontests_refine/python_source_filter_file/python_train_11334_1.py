def get_input():
    while True:
        try:
            yield ''.join(input())
        except EOFError:
            break

teams = [0 for i in range(101)]
points = [False for i in range(31)]
while True:
    a,b = [int(i) for i in input().split(",")]
    if a == 0 and b == 0:
        break

    teams[a] = b
    points[b] = True

N = list(get_input())
for l in range(len(N)):
    q = int(N[l])
    p = teams[q]
    ans = 0
    for i in range(30,0,-1):
        if points[i]:
            ans += 1
        if i == p:
            break
    print(ans)

