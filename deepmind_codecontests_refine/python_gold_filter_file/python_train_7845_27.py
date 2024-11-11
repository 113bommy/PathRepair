#in
t = int(input())
a = []
for i in range(0, t):
    a.append(int(input()))

#comp
def IsRegPolygon(p):
    if 360%(180-p) == 0:
        return "YES"
    else:
        return "NO"

ans = []
for i in a:
    ans.append(IsRegPolygon(i))

#out
for i in ans:
    print(i) 