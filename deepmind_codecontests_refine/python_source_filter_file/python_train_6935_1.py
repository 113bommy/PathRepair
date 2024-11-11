h, m, s, t1, t2 = map(int, input().split())


# ps = s / 5
# pm = (m  + s / 60) / 5
# ph = h + m / 60 + s / 3600

k = min(t1, t2)
t = max(t1, t2)

l = 0

if(s > k * 5 and s < t * 5):
    l += 1
if(m > k * 5 and m < t * 5):
    l += 1
if(h >= k and h < t):
    l += 1

if(l > 0 and l < 3):
    print("NO")
else:
    print("YES")
    

