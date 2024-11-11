

n = int(input())

a = list(map(int, input().split()))


p1 = 0
p2 = n - 1

m = 0
s = ""

while p1 <= p2:

    if m < a[p1] < a[p2]:
        s += ('L')
        m = a[p1]
        p1 += 1

    elif a[p1] <= m < a[p2]:
        s += ('R')
        m = a[p2]
        p2 -= 1
    elif m < a[p2] < a[p1]:
        s += ('R')
        m = a[p2]
        p2 -= 1
    elif a[p2] <= m < a[p1]:
        s += ('L')
        m = a[p1]
        p1 += 1

    elif a[p1] <= m and a[p2] <= m:
        break
    elif p1 == p2:
        s += ('R')
        p1 += 1
    elif a[p1] == a[p2] and a[p1] > m:

        sp2 = "R"
        p22 = p2

        while p22 > p1 and a[p22-1] > a[p22]:
            sp2 += 'R'
            p22 -= 1

        sp1 = "L"
        p11 = p1

        while p11 < p2 and a[p11+1] > a[p11]:
            sp1 += "L"
            p11 += 1

        if len(sp2) > len(sp1):
            s += sp2
        else:
            s += sp1

        break
    else:
        break
            



print (len(s))
print (s)

