def find(a,b):
    for i in range(9):
        if aliceK[i][0] == a and aliceK[i][1] == b:
            return [aliceA[i], bobA[i]]
 
def winner(m, n):
 
    if m == n:
        return 0
    if m == 3 and n == 2:
        return 1
    elif m == 2 and n == 1:
        return 1
    elif m == 1 and n == 3:
        return 1
    else:
        return 2
 
kk, a, b = map(int, input().split())
 
aliceK = [[],[],[],[],[],[],[],[],[]]
aliceA = []
bobK = [[],[],[],[],[],[],[],[],[]]
bobA = []
#----------------------------------------------ZAPOLNYAEM_MASSIVI-----------------------------------------------------------------------
k = int(0)      
for i in range(3):
    n = list(map(int, input().split()))
    for j in range(3):
        aliceK[k].append(i+1)
        aliceK[k].append(j+1)
        aliceA.append(n[j])
        k += 1
 
k = 0
for i in range(3):
    n = list(map(int, input().split()))
    for j in range(3):
        bobK[k].append(i+1)
        bobK[k].append(j+1)
        bobA.append(n[j])
        k += 1
#----------------------------------------------ZAPOLYAEM_USED----------------------------------------------------------------------
used = []
used.append([a,b])
for i in range(9):
    l = find(a, b)
    used.append(l)
    a = l[0]
    b = l[1]
#----------------------------------------------ISCHEM_DLINNY_CIKLA----------------------------------------------------------------------
lenC = 0
start = 0
finish = 0
flag = 0
for i in range(9):
    for j in range(i+1, 10):
        if used[i][0] == used[j][0] and used[i][1] == used[j][1]:
            lenC = j - i
            start = i
            finish = j
            flag = 1
            break
    if flag == 1:
        break
#----------------------------------------------SCHITAEM_KOL-VO_DENEG_Y_ALISI_I_BOBA_ZA_CIKL---------------------------------------
moneyCA = 0
moneyCB = 0
 
for i in range(start, finish):
    winnerr = winner(used[i][0], used[i][1])
    if winnerr == 1:
        moneyCA += 1
    elif winnerr == 2:
        moneyCB += 1
#----------------------------------------------SCHITAEM_KOL-VO_DENEG_Y_ALISI_I_BOBA_DO_CIKLA---------------------------------------
AllMoneyA = 0
AllMoneyB = 0
 
for i in range(start):
    winnerr = winner(used[i][0], used[i][1])
    if winnerr == 1:
        AllMoneyA += 1
    elif winnerr == 2:
        AllMoneyB += 1
#---------------------------------------------SCHITAEM_KOL-VO_DENEG_ZA_VSE_KROME_KONCA,_ESCHO_SCHITAEM_KONEC----------------------------------------
if kk < lenC:
    AllMoneyA = 0
    AllNoneyB = 0
    for i in range (kk):
        winnerr = winner(used[i][0], used[i][1])
        if winnerr == 1:
            AllMoneyA += 1
        elif winnerr == 2:
            AllMoneyB += 1 
    print(AllMoneyA, AllMoneyB)
    exit()
AllMoneyA += (kk-start)//lenC * moneyCA
AllMoneyB += (kk-start)//lenC * moneyCB
dopZopa = (kk-start) - (kk-start)//lenC * lenC
#---------------------------------------------SCHITAEM_KOL-VO_DENEG_ZA_VSE_KROME_KONCA,_ESCHO_SCHITAEM_KONEC----------------------------------------
for i in range(start, dopZopa + start):
    winnerr = winner(used[i][0], used[i][1])
    if winnerr == 1:
        AllMoneyA += 1
    elif winnerr == 2:
        AllMoneyB += 1
#--------------------------------------------------------------------------KONEC----------------------------------------
print(AllMoneyA, AllMoneyB)