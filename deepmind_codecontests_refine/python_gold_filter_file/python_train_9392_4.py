from sys import stdin, stdout

t = int(stdin.readline().strip())

for _ in range(t):
    a,b,c,r = map(int, stdin.readline().split())
    v = b-a
    ans = None
    if v == 0:
        ans = 0
    else:
        v = v//abs(v)
        r1,r2 = c-r,c+r
        ans = min((b-a)*v, max(0,(c-a)*v - r) + max(0,(b-c)*v-r))
    stdout.write("{}\n".format(ans))
