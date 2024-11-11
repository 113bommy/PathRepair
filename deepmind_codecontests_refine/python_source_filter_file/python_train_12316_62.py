k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

if min(k, l, m, n) == 1:
    print(d)
    exit()
else:
    s = 0
    for j in range(1, d+1):
        if j % k == 0:
            s+=1
        elif j % l == 0:
            s+=1
        elif j % m == 0:
            s+=1
        elif j % n == 0:
            s+=1
    if s <= 0:
        print(d)
    else:
        print(s)