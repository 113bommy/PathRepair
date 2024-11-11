import math
x, y, z = map(int, input().split())
a, b, c = map(int, input().split())
s, rs, ls = map(int, input().split())
def rec(ss):
    for i in range(0, 155, 1):
        for j in range(0, 155, 1):
            if(i * rs + j * ls <= ss):
                q = y + i;p = z + j; pq = x + ((int)((ss - i * rs - j *ls) / s))
                an1 = 1000000000000.0;an2 = 1000000000000.0
                if(b - p > 0):
                    an1 = math.ceil(((float) (pq)) / ((float)(b - p)))
                if(q - c > 0):
                    an2 = math.ceil(((float) (a)) / ((float)(q - c)))
                if(q > c and p >= b or an1 > an2):
                    return True
    return False
st = 0; en = 100000; mid = 0
while(st <= en):
    mid = (int)((st + en) / 2)
    if(rec(mid) == True):
        en = mid - 1
    else:
        st = mid + 1
print(en + 1)