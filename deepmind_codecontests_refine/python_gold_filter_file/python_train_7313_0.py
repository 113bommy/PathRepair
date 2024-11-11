
for ss in range(int(input())):
    n, k = input().strip().split()
    n = int(n)
    k = int(k)
    list = []
    ilist = []
    klaar = True
    for i in range(10):
        m = 0
        for t in range(k + 1):
            s = i + t
            if s >= 10:
                s = s - 9
            m = m + s
        if ((i == 0) and m > n):
            print(-1)
            klaar = False
            break
        if (((n - m) % (k + 1)) == 0) and (n > m):
            list.append(m)
            ilist.append(i)
        if n == m:
            print(i)
            klaar = False
            break
        if not(klaar):
            break
#        print("output: "+str(i))
#        print("m: "+str(m))
# get max m waarde van list [m1, m2, m3, ... , mn]
    if klaar:
        if not(list):
            print(-1)
            continue
        else:
            i = ilist[list.index(max(list))]
            if ((i + k) < 10) or (((i + k) >= 10) and (int((n - max(list))/(k + 1)) < 9)):
                lom = int((n - max(list))/(k + 1))
                print(int(str(lom % 9) + ((lom // 9) * "9") + str(i)))
            else:
                lom = int(((n - max(list))/(k + 1)) - 8)
                print(int(str(lom % 9) + ((lom // 9) * "9") + "8" + str(i)))
