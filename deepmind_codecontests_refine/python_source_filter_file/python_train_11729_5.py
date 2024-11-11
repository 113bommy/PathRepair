n = int(input())
one = input()
two = input()
thr = input()
d1 = {}
d2 = {}
d3 = {}
m1 = 0
m2 = 0
m3 = 0
l = len(one)

def f(q):
    if q == l and n == 1:
        return n - 1
    if q == l:
        return l - n % 2
    if q + n <= l:
        return q + n
    else:
        return l
for i in range(len(one)):
    try:
        d1[one[i]] += 1
    except KeyError:
        d1[one[i]] = 1
    #m1 = max(m1, f(d1[one[i]]))
for i in range(len(one)):
    try:
        d2[two[i]] += 1
    except KeyError:
        d2[two[i]] = 1
    #m2 = max(m2, f(d2[two[i]]))
for i in range(len(one)):
    try:
        d3[thr[i]] += 1
    except KeyError:
        d3[thr[i]] = 1
    #m3 = max(m3, f(d3[thr[i]]))
for i in range(l):
    m1 = max(m1, f(d1[one[i]]))
    m2 = max(m2, f(d2[two[i]]))
    m3 = max(m3, f(d3[thr[i]]))
# print(d1, d2, d3)
l = len(one)
#print(m1, m2, m3)
if [m1, m2, m3].count(max(m1, m2, m3)) != 1:
    print('Draw')
    exit()
if max(m1, m2, m3) == m1:
    print('Kuro')
elif max(m1, m2, m3) == m2:
    print('Shiro')
else:
    print('Katie')