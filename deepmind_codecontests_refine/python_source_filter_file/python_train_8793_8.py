n, m = input().split(' ')
n = int (n)
m = int(m)
count = 0
if n > m :
    print(m - n)
else :
    c = m
    while c > n:
        if c % 2 == 0:
            c = m // 2
            count += 1
        else :
            c = (m + 1) // 2
            count += 2
            
    print(count + (n - c))