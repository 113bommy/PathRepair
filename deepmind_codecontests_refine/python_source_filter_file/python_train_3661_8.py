n, q = map(int,input().split())
ai = list(map(int,input().split()))
ar  = []
ar3 = []
num = 0
nummm = max(ai)
if ai[0] != n:
    num2 = ai[0]
    for i in range(1,n):
        ar3 += [[num2,ai[i]]]
        if ai[i] == nummm:
            ar += [num2]
            num = i+1
            break
        if ai[i] > num2:
            ar += [num2]
            num2 = ai[i]
        else:
            ar += [ai[i]]
ar2 = []
for i in range(num,n):
    ar2 += [ai[i]]
for i in range(len(ar)):
    ar2 += [ar[i]]
num = len(ar3)
for i in range(q):
    m = int(input())
    if m <= num:
        print(ar3[m-1][0],ar3[m-1][1])
    else:
        m -= num
        m -= 1
        print(n,ar2[m % (n-1)])
