import math

t = int(input().split()[0])
for case in range(t):
    n = int(input().split()[0])
    s = input().split()[0]
    pt = -1
    for i in range(n):
        if s[i] == 'R' and s[(i+1)%n] == 'L':
            pt = (i+1)%n
            break
    if pt == -1:
        print((n+1)//3)
        continue
    curr = (pt+1) % n
    streak = "N"
    ct = 0
    ans = 0
    while curr != pt:
        if streak == "N":
            streak = s[curr]
            ct = 1
        elif streak == "R":
            if s[curr] == "L":
                streak = "N"
                ans += (ct) // 3
            else:
                ct += 1
        else:
            if s[curr] == "R":
                ans += (ct+1) // 3
                streak = "R"
                ct = 1
            else:
                ct += 1
        curr = (curr+1) % n
    ans += ct // 3
    print(ans)
