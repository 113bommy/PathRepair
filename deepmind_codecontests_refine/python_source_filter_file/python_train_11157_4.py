a = int(input())
ot = ''
for i in range(a):
    b, c = map(int,input().split())
    s = input()
    pref = [0] * (b + 1)
    pref1 = [0] * (b + 1)
    pref2 = [0] * (b + 1)
    n = 'RGB'
    n1 = 'GBR'
    n2 = 'BRG'
    for j in range(b):
        pref[j + 1] = pref[j]
        if s[j] != n[j % 3]:
            pref[j + 1] += 1
        pref1[j + 1] = pref1[j]
        if s[j] != n1[j % 3]:
            pref1[j + 1] += 1
        pref2[j + 1] = pref2[j]
        if s[j] != n2[j % 3]:
            pref2[j + 1] += 1
    mi = 1000000000
    #print(*pref)
    #print(*pref1)
    #print(*pref2)
    for j in range(c, b + 1):
        mi = min(pref[j] - pref[j - c], pref1[j] - pref1[j - c], pref2[j] - pref2[j - c], mi)
        #print(mi, j)
    mi = min(pref[-1], pref1[-1], pref2[-1],  mi)
    ot += str(mi) + '\n'
print(n)
