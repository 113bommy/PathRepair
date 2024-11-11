x, k = list(map(int,input().split()))
tot = 0
now = 1
d = 1
ans = []
def add(am,el):
    global ans
    ans += [el]*am
def rec(l):
    global d
    global tot
    now = 1
    while True:
        if tot + (2**now - 1) > x:

            if (tot-len(ans) ) != 0:
                rec(x-len(ans))
            break

        tot+=(2**now - 1)
        add(now,d)
        now+=1
        d+=k
        if tot == x:
            break
rec(x)
print(len(ans))
print(*ans)
