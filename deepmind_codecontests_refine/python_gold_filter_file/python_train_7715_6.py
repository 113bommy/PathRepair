n = int(input())
s = input()
p,q = input().split()
if p[0] == '-':
    x = -1*int(p[1:])
else:
    x = int(p)
if q[0] == '-':
    y = -1*int(q[1:])
else:
    y = int(q)
cur = [0,0]
if(abs(x)+abs(y) > n):
    print(-1)
elif((x+y)%2 != n%2):
    print(-1)
else:
    end = n
    for i in range(n):
        if s[i] == "R":
            cur[0] += 1
        if s[i] == "L":
            cur[0] -= 1
        if s[i] == "U":
            cur[1] += 1
        if s[i] == "D":
            cur[1] -= 1
        if(abs(x-cur[0])+abs(y-cur[1]) >= n-i):
            end = i
            break
    if end == n:
        print(0)
    else:
        m = [0]*(end+1)
        start = n
        for i in range(end,-1,-1):
            if s[i] == "R":
                cur[0] -= 1
            if s[i] == "L":
                cur[0] += 1
            if s[i] == "U":
                cur[1] -= 1
            if s[i] == "D":
                cur[1] += 1
            while(abs(x-cur[0])+abs(y-cur[1]) <= start-i):
                start -= 1
                if s[start] == "R":
                    x -= 1
                if s[start] == "L":
                    x += 1
                if s[start] == "U":
                    y -= 1
                if s[start] == "D":
                    y += 1
            m[i] = start-i+1
        minn = n
        for i in m:
            minn = min(minn,i)
        print(minn)
