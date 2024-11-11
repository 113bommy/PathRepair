input = __import__("sys").stdin.readline

oo = 10**15
n = int(input())

a = list(map(int, input().split()))

sol = rsol = 0
last = rlast = ""
for i in range(n):
    w = input()
    rw = w[::-1]
    
    #print(w, rw, last, rlast)
    curr = rcurr = oo
    if w >= last:
        curr = min(curr, sol)
    if w >= rlast:
        curr = min(curr, rsol)
    if rw >= last:
        rcurr = min(rcurr, sol + a[i])
    if rw >= rlast:
        rcurr = min(rcurr, rsol + a[i])

    #print(curr, rcurr)
    last, rlast = w, rw
    sol, rsol = curr, rcurr

sol = min(sol, rsol)

if sol >= oo:
    print(-1)
else:
    print(sol)


    