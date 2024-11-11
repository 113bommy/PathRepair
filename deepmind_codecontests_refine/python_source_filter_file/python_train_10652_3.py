q = 'abcdefghijklmnopqrstuvwxyz'
s = ''

n = int(input())
for _ in range(n):
    e = input()
    p = e.find('a')    
    p1 = p - 1
    p2 = p + 1
    p3 = 0
    res = "NO"
    if p > -1:
        res = "YES"
        while (p2 - p1) < len(e) + 1:
            print(p1, p2, p3)
            p3 += 1
            if (p1 > -1 and e[p1] == q[p3]):
                p1 -= 1
            elif (p2 < len(e) and e[p2] == q[p3]):
                p2 += 1
            else:
                res = "NO"
                break
    print(res)

'''
1
ddcba

2
a
ba
'''