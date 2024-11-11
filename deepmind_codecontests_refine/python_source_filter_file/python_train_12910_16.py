def check(T, p, n, k):
    i = 0
    
    for j in range(k):
        s = 0
       
       while(s+T[i] <= p):
            s += T[i]
            i += 1
            if i == n:
                return n
    
    return i

n, k = [int(x) for x in input().split()]
T = []
for i in range(n):
    T.append(int(input()))

left, right = 0, 100000 * 10000

while(right - left > 1):
    mid = (left + right) / 2
    if (check(T, mid, n, k) >= n):
        right = mid
    else:
        left = mid

print right