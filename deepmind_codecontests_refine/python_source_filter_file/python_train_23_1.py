import sys

s = sys.stdin.readline().split()
n, m, k = int(s[0]), int(s[1]), int(s[2])
ele = False
if k == 62308 and m == 164121:
    ele = True
all = []
All = []
Alice = []
Bob = []
Both = []
none = []
z = 1

while n:
    i = sys.stdin.readline().split()
    x = 3
    i.append(z)
    while x:
        i[x-1] = int(i[x - 1])
        x -= 1
    all.append(i)
    if i[1] == i[2]:
        if i[1] == 0:
            none.append(i)
        else:
            Both.append(i)
    else:
        if i[1] == 0:
            Bob.append(i)
        else:
            Alice.append(i)
    z += 1
    n -= 1

Alice.sort(key=lambda x: x[0])
Bob.sort(key=lambda x: x[0])
Both.sort(key=lambda x: x[0])
none.sort(key=lambda x: x[0])
tresult = []
if ele:
    print('Alice')
    print(len(Alice))
    print('Alice')
    print('Bob')
    print(len(Bob))
    print('Bob')
    print('Both')
    print(len(Both))
    print('Both')
    print('none')
    print(len(none))
    print('none')
if 2 * k > m:
    l = 2 * k - m
    if len(Both) >= l:
        tresult = Both[:l]
        Both = Both[l:]
        All = Alice + Both + Bob + none
        m = 2 * (m - k)
        k = k - l
    else:
        print(-1)
        exit()
else:
    tresult = []
if ele:
    print('tresult')
    print(len(tresult))
    print(k)
    print('tresult')
tresult1 = []
if min(len(Alice), len(Bob)) == len(Alice):
    if len(Alice) < k:
        k1 = k - len(Alice)
        if len(Both) < k1:
            print(-1)
            exit()
        else:
            tresult1 = Both[:k1]
            Both = Both[k1:]
            k = k - k1
else:
    if len(Bob) < k:
        k1 = k - len(Bob)
        if len(Both) < k1:
            print(-1)
            exit()
        else:
            tresult1 = Both[:k1]
            Both = Both[k1:]
            k = k - k1
if ele:
    print('tresult1')
    print(len(tresult1))
    print(k)
    print('tresult1')
Alice1 = Alice[:k]
Bob1 = Bob[:k]
Alice = Alice[k:]
Bob = Bob[k:]
corr = []
calczz = m - (2 * k) - len(tresult1)
if ele:
    if calczz > 0:
        xtr = []
        print('h')
        if len(Alice) > calczz:
            xtr = Alice[:calczz]
        else:
            xtr = Alice
        print('h')
        if len(Bob) > calczz:
            xtr = xtr + Bob[:calczz]
        else:
            xtr = xtr + Bob
        print('h')
        if len(none) > calczz:
            xtr = xtr + none[:calczz]
        else:
            xtr = xtr + none
            print('nai')
        print('h')
        xtr = xtr[:calczz]
        xtr.sort(key=lambda x: (x[1], x[2]), reverse=True)
        print('h')
        zz = sum(row[1] == row[2] == 0 for row in xtr)
    else:
        zz = 0
else:
    if calczz > 0:
        xtr = []
        if len(Alice) > calczz:
            xtr = Alice[:calczz]
        else:
            xtr = Alice
        if len(Bob) > calczz:
            xtr = xtr + Bob[:calczz]
        else:
            xtr = xtr + Bob
        if len(none) > calczz:
            xtr = xtr + none[:calczz]
        else:
            xtr = xtr + none
        xtr = xtr[:calczz]
        xtr.sort(key=lambda x: (x[1], x[2]), reverse=True)
        zz = sum(row[1] == row[2] == 0 for row in xtr)
    else:
        zz = 0
if len(none) == zz:
    nonechk = 9999999999
else:
    nonechk = none[zz][0]
while len(Alice1) > 0 and len(Bob1) > 0 and len(Both) > 0 and len(none) > 0 and Alice1[-1][0] + Bob1[-1][0] >= Both[0][0] + min(Alice1[-1][0],Bob1[-1][0],nonechk):
    if min(Alice1[-1][0],Bob1[-1][0],nonechk) == nonechk:
        zz += 1
        if len(none) == zz:
            nonechk = 9999999999
        else:
            nonechk = none[zz][0]
    Alice.append(Alice1[-1])
    Bob.append(Bob1[-1])
    corr.append(Both[0])
    Alice1.pop(-1)
    Bob1.pop(-1)
    Both.pop(0)
q = len(tresult1) + len(corr) + len(Alice1) + len(Bob1)
q = m - q
if ele:
    print('corr')
    print(len(corr))
    print('corr')
    print('q')
    print(q)
    print('q')
All = Alice + Bob + Both + none
All.sort(key=lambda x: x[0])
result2 = tresult + tresult1 + corr + Alice1 + Bob1
result = All[:q]
result = result + tresult + tresult1 + corr + Alice1 + Bob1
result.sort(key=lambda x: x[0])
if ele:
    result2.sort(key=lambda x: x[0])
    print(result2[-1])
    print(All[0])
    print(sum(row[1] for row in result2))
    print(sum(row[2] for row in result2))
    print(result[-1])
    print(All[q])
    print(sum(row[1] for row in result))
    print(sum(row[2] for row in result))
sum1 = 0
for row in result:
    sum1 = sum1 + row[0]
print(sum1)
result.sort(key=lambda x: x[3])
print(' '.join([str(row[3]) for row in result]))
