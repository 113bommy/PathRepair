from collections import Counter
n = int(input())
a = list(map(int,input().split()))
a.sort()
b = list(set(a))
c = Counter(a)
if c[b[0]] >= 3:
    k = c[b[0]]
    print(int(k*(k-1)*(k-2)/6))
else:
    k = c[b[0]]
    if len(b) == 1:
        j = 0
    else:
        j = c[b[1]]
    if k == 2:
        print(j)
    elif k == 1:
        if j >= 3:
            print(int(j*(j-1)/2))
        elif j == 2:
            print(1)
        else:
            if len(b) <= 2:
                print(0)
            else:
                print(c[b[2]])
