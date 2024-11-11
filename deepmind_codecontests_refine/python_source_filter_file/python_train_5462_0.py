__author__ = 'zhan'

import time
[a1, b1] = [int(i) for i in input().split()]
[a2, b2] = [int(i) for i in input().split()]

t0 = time.time()
q1 = [[a1, b1, 0]]
q2 = [[a2, b2, 0]]
tested1 = []
tested2 = []
tested_total1 = []
tested_total2 = []


def equal(t, q):
    lo = 0
    hi = len(q)
    while True:
        if lo >= hi:
            return False
        m = (lo + hi) // 2
        p = q[m]
        temp = p[0] * p[1]
        if t == temp:
            return [p[0], p[1], p[2]]
        if t < temp:
            lo = m + 1
        elif t > temp:
            hi = m


def found(key, a):
    lo = 0
    hi = len(a)
    while True:
        if lo >= hi:
            return False
        m = (lo + hi) // 2
        p = a[m]
        if key[0] == p[0] and key[1] == p[1]:
            return True
        if key[0] < p[0] or key[0] == p[0] and key[1] < p[1]:
            lo = m + 1
        if key[0] > p[0] or key[0] == p[0] and key[1] > p[1]:
            hi = m


while True:
    if len(q1) > 0 and len(q2) > 0:
        total1 = q1[0][0] * q1[0][1]
        total2 = q2[0][0] * q2[0][1]
        if total1 > total2:
            ans = equal(total1, q2)
            if ans:
                print(str(ans[2] + q1[0][2]) + "\n" + str(q1[0][0]) + " " + str(q1[0][1]) + "\n" + str(ans[0]) + " " + str(ans[1]))
            else:
                if not(q1[0][0] & 1):
                    tt = [q1[0][0] // 2, q1[0][1], q1[0][2] + 1]
                    #if len(tested1) == 0 or (not found([tt[0], tt[1]], tested1)):
                    if (not [tt[0], tt[1]] in tested1) and (not tt[0]*tt[1] in tested_total1):
                        tested1.append([tt[0], tt[1]])
                        q1.append(tt)
                        tested_total1.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q2)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if q1[0][0] % 3 == 0:
                    tt = [q1[0][0] // 3 * 2, q1[0][1], q1[0][2] + 1]
                    #if len(tested1) == 0 or (not found([tt[0], tt[1]], tested1)):
                    if (not [tt[0], tt[1]] in tested1) and (not tt[0]*tt[1] in tested_total1):
                        tested1.append([tt[0], tt[1]])
                        q1.append(tt)
                        tested_total1.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q2)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if not(q1[0][1] & 1):
                    tt = [q1[0][0], q1[0][1] // 2, q1[0][2] + 1]
                    #if len(tested1) == 0 or (not found([tt[0], tt[1]], tested1)):
                    if (not [tt[0], tt[1]] in tested1) and (not tt[0]*tt[1] in tested_total1):
                        tested1.append([tt[0], tt[1]])
                        q1.append(tt)
                        tested_total1.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q2)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if q1[0][1] % 3 == 0:
                    tt = [q1[0][0], q1[0][1] // 3 * 2, q1[0][2] + 1]
                    #if len(tested1) == 0 or (not found([tt[0], tt[1]], tested1)):
                    if (not [tt[0], tt[1]] in tested1) and (not tt[0]*tt[1] in tested_total1):
                        tested1.append([tt[0], tt[1]])
                        q1.append(tt)
                        tested_total1.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q2)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                q1.pop(0)
                q1.sort(key=lambda x: x[0]*x[1], reverse=True)
                #tested1.sort(key=lambda x: (x[0], x[1]), reverse=True)

        elif total1 < total2:
            ans = equal(total2, q1)
            if ans:
                print(str(ans[2] + q2[0][2]) + "\n" + str(ans[0]) + " " + str(ans[1]) + "\n" + str(q2[0][0]) + " " + str(q2[0][1]))
                break
            else:
                if not(q2[0][0] & 1):
                    tt = [q2[0][0] // 2, q2[0][1], q2[0][2] + 1]
                    #if len(tested2) == 0 or (not found([tt[0], tt[1]], tested2)):
                    if (not [tt[0], tt[1]] in tested2) and (not tt[0]*tt[1] in tested_total2):
                        tested2.append([tt[0], tt[1]])
                        q2.append(tt)
                        tested_total2.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q1)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if q2[0][0] % 3 == 0:
                    tt = [q2[0][0] // 3 * 2, q2[0][1], q2[0][2] + 1]
                    #if len(tested2) == 0 or (not found([tt[0], tt[1]], tested2)):
                    if (not [tt[0], tt[1]] in tested2) and (not tt[0]*tt[1] in tested_total2):
                        tested2.append([tt[0], tt[1]])
                        q2.append(tt)
                        tested_total2.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q1)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if not(q2[0][1] & 1):
                    tt = [q2[0][0], q2[0][1] // 2, q2[0][2] + 1]
                    #if len(tested2) == 0 or (not found([tt[0], tt[1]], tested2)):
                    if (not [tt[0], tt[1]] in tested2) and (not tt[0]*tt[1] in tested_total2):
                        tested2.append([tt[0], tt[1]])
                        q2.append(tt)
                        tested_total2.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q1)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                if q2[0][1] % 3 == 0:
                    tt = [q2[0][0], q2[0][1] // 3 * 2, q2[0][2] + 1]
                    #if len(tested2) == 0 or (not found([tt[0], tt[1]], tested2)):
                    if (not [tt[0], tt[1]] in tested2) and (not tt[0]*tt[1] in tested_total2):
                        tested2.append([tt[0], tt[1]])
                        q2.append(tt)
                        tested_total2.append(tt[0]*tt[1])
                        an = equal(tt[0]*tt[1], q1)
                        if ans:
                            print(str(an[2] + tt[2]) + "\n" + str(tt[0]) + " " + str(tt[1]) + "\n" + str(an[0]) + " " + str(an[1]))
                q2.pop(0)
                q2.sort(key=lambda x: x[0]*x[1], reverse=True)
                #tested2.sort(key=lambda x: (x[0], x[1]), reverse=True)

        else:
            print(str(q1[0][2] + q2[0][2]) + "\n" + str(q1[0][0]) + " " + str(q1[0][1]) + "\n" + str(q2[0][0]) + " " + str(q2[0][1]))
            break
    else:
        print(-1)
        break

t1 = time.time()
print(t1-t0)