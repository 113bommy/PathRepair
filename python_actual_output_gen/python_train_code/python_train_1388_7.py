import sys
readline = sys.stdin.readline

h, m = map(int, readline().split())
T = h*60+m
dic = 20*60+0
H, D, C, N = map(int, readline().split())

if T < dic:
    ans = min((-(-H//N)*C, -(-(H+(dic-T)*D)//N)*(C*0.8)))
else:
    ans = -(-H//C)*C*0.8
print(ans)