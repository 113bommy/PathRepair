def takefirst(a, s):
    curs = 0
    for i in range(len(a)):
        curs += a[i]
        if curs == s:
            return i
        if curs > s:
            return -1
    return -1

def maxid(a):
    if len(a) == 1: return 0
    m = max(a)
    if a[0] == m:
        if a[1] < m: return 0
    if a[-1] == m:
        if a[-2] < m: return len(a)-1
    for i in range(1,len(a)-1):
        if a[i] == m:
            if a[i+1] < m or a[i-1] < m:
                return i
    return a.index(m)

def maxid1(a):
    m = a[0]
    mid = 0
    for i in range(len(a)):
        if m < a[i]:
            m = a[i]
            mid = i
            continue
        if m == a[i]:
            mid = i
    if mid == len(a) - 1:
        for i in range(len(a)):
            if a[i] == m:
                return i
    return mid

n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
step = []
flag = True
o = 0
for i in b:
    take = takefirst(a,i)
    if take == -1:
        #NO
        flag = False
        break
    else:
        considering = a[:take+1]
        a = a[take+1:]
        #print(considering)
        if len(considering) <= 1:
            o += 1
            continue
        biggest = maxid(considering)
        ii = biggest
        #print(ii,take)
        #print("a",a)
        if biggest < take and considering[biggest] > considering[biggest+1]:
            while(ii < take):
                step.append(str(biggest+1+o) + " R")
                ii += 1
            while(biggest > 0):
                step.append(str(biggest+1+o) + " L")
                biggest -= 1
        elif biggest > 0 and considering[biggest] > considering[biggest-1]:
            while(biggest > 0):
                step.append(str(biggest+1+o) + " L")
                biggest -= 1
            while(ii < take):
                step.append(str(1+o) + " R")
                ii += 1
        elif biggest == 0 and considering[biggest] > considering[biggest+1]:
            while(ii < take):
                step.append(str(biggest+1+o) + " R")
                ii += 1
        elif biggest == take and considering[biggest] > considering[biggest-1]:
            while(biggest > 0):
                step.append(str(biggest+1+o) + " L")
                biggest -= 1
        else:
            flag = False
        #print("step", step)
        o += 1
if len(a) > 0:
    flag = False
if not flag:
    print("NO")
else:
    print("YES")
    if len(step) > 0:
        print("\n".join(step))
