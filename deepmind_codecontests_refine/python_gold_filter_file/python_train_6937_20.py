n, pos, l, r = map(int, input().split())
pos -= 1
l -= 1
r -= 1
v = [0]*(n)
for i in range(l, r+1):
    v[i] = 1
t = 0
while v.count(0) != 0:
    if l == 0:
        t += abs(pos - r) + 1
        for i in range(r+1, n):
            v[i] = 1
    elif r == n-1:
        t += abs(pos - l) + 1
        for i in range(0, l):
            v[i] = 1        
    else:
        if abs(pos - l) <= abs(pos - r):
            t += abs(pos - l)
            pos = l
            for i in range(0, l):
                v[i] = 1
            t += 1
            t += abs(pos - r)
            for i in range(r+1, n):
                v[i] = 1
            t+=1
        else:
            t += abs(pos - r)
            pos = r
            for i in range(r+1, n):
                v[i] = 1
            t+=1 
            t += abs(pos - l)
            for i in range(0, l):
                v[i] = 1
            t += 1            
print(t)                        