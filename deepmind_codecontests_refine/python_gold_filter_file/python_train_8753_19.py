# http://codeforces.com/contest/1015/problem/D
# 10 2 15

def next_step(pos, step):
    if pos-step > 0:
        return pos-step
    else:
        return pos+step

n, k, s  = [int(x) for x in input().split()]
if s < k or k * (n-1) < s:
    print('NO')
else:
    print('YES') 
    pos = 1
    while k:
        dist = min(n-1, s-(k-1))
        pos = next_step(pos, dist)
        print(pos, end=' ')
        s -= dist
        k -= 1



