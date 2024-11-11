import math

def lerp(val, lb, ub, lv, uv): return lv + (val-lb)*(uv-lv)/(ub-lb)
def get_ints(): return list(map(int, input().split()))
def get_floats(): return list(map(float, input().split()))

M,N = get_ints()

if N < M-1 or N > 3*(M+1):
    print(-1)
    exit()

N -= M-1

s = ""
for i in range(M-1):
    s += "0"
    s += "1" + "1"*int(N > 0)
    if N > 0: N -= 1

s += "0"

if N == 1:
    s = "1" + s
elif N == 2:
    s = "11"+s
elif N==3:
    s = "11"+s + "1"

elif N==4:
    s = "11"+s + "11"

print(s)