NTEST = 26

D=int(input())

C=list(map(int,input().split()))

SL=list()
SL.append([0 for i in range(NTEST)])
for d in range(D):
    S=list(map(int,input().split()))
    SL.append(S)

tests=list()
tests.append(0)
for d in range(D):
    tests.append(int(input()))

def calcSat(test_applied):
    lastDay = [0 for i in range(NTEST)]

    sat = 0
    for d in range(1,D+1):
        tst = test_applied[d] - 1
        lastDay[tst] = d
        sat += SL[d][tst]
        for itst in range(NTEST):
            sat -= C[itst] * (d-lastDay[itst])
    return sat

satList = list()
satList.append(0)
lastDay = [[0 for i in range(NTEST)]]

def calcSat_with_memo(test_applied):

    total_sat = 0
    for d in range(1,D+1):
        lastDay.append(list(lastDay[d-1]))
        sat = 0
        tst = test_applied[d] - 1
        lastDay[d][tst] = d
        sat += SL[d][tst]
        for itst in range(NTEST):
            sat -= C[itst] * (d-lastDay[d][itst])
        satList.append(sat)
        total_sat += sat

    return total_sat

def recalcSat_with_memo(total_sat_before, tday, t_from, t_to, test_applied):

    d_total_sat = 0

    lastDay[tday][t_from -1]=lastDay[tday-1][t_from -1]
    d_sat=0
    d_sat += (SL[tday][t_to -1]-SL[tday][t_from -1])
    d_sat += C[t_to -1]*(tday - lastDay[tday][t_to -1])
    d_sat -= C[t_from -1]*(tday - lastDay[tday][t_from -1])

    lastDay[tday][t_to -1]=tday

    satList[tday]+= d_sat
    d_total_sat  += d_sat

    old_last = tday
    new_last = lastDay[tday][t_from -1]
    for d in range(tday+1,D+1):
        if test_applied[d] == t_from :
            break
        d_sat = C[t_from -1]*(- old_last + new_last)
        lastDay[d][t_from -1] = new_last
        satList[d]+= d_sat
        d_total_sat += d_sat

    old_last = lastDay[tday-1][t_to -1]
    new_last = tday
    for d in range(tday+1,D+1):
        if test_applied[d] == t_to :
            break
        d_sat = C[t_to -1]*(- old_last + new_last)
        lastDay[d][t_to -1] = new_last
        satList[d]+= d_sat
        d_total_sat += d_sat
            
    return d_total_sat


# sat = calcSat(tests)
# print(sat)

sat = calcSat_with_memo(tests)
print(sat)


# -------------------
M=int(input())

ans = list()

for m in range(M):
    d, new_tst = list(map(int, input().split()))

    d_sat = recalcSat_with_memo(sat, d, tests[d], new_tst, tests)

    tests[d] = new_tst
    sat += d_sat
    ans.append(sat)

for m in range(M):
    print(ans[m])

