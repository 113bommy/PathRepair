n = int(input())
a = list(map(int, input().split()))
a.append(0)
for i in range(n):
    a[n] ^= a[i]
    #全ての排他的論理和を求める。→興味があるのは、2進数で1が偶数個立ってる列。
    #ここでa[n]に奇数個しか1がないもの
for i in range(n):
    a[i] &= ~a[n]
r = 0
for i in range(60, -1, -1):
    for j in range(r, n):
        if (a[j] >> i) & 1:
            a[r], a[j] = a[j], a[r]
            break
    else:
        continue
        
    for j in range(n):
        if (a[j] == a[r]):
            continue
        if (a[j]>>i) & 1:
            a[j] ^= a[r]
    r+=1
s = 0
for i in range(r):
    s ^= a[i]
    
print(s*2 + a[n])