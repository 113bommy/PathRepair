n, k = map(int, input().split())

a = [int(i) for i in input().split()]

w = []
r = []
o = []

s = input()

for i in range(n):
    if s[i] == 'O':
        o.append(a[i])
    if s[i] == 'R':
        r.append(a[i])
    if s[i] == 'W':
        w.append(a[i])

o.sort(), w.sort(), r.sort()

w = w[::-1]
o = o[::-1]
r = o[::-1]

ans = -1
i = 0
j = 0
cntf = 0
cnts = 0
nw = 0

while (cntf + cnts) < k and (i < len(w) or j < len(o)):
    if(i >= len(w)):
        nw += o[j]
        j += 1
        cnts += 1
    elif(j >= len(o)):
        nw += w[i]
        i += 1
        cntf += 1
    else:
        if(w[i] > o[j]):
            nw += w[i]
            i += 1
            cntf += 1
        else:
            nw += o[j]
            j += 1
            cnts += 1
    
    if(cntf + cnts == k - 1):
        if(cntf == 0 and len(w) != 0):
            nw += w[i]
            cntf += 1
        elif(cnts == 0 and len(o) != 0):
            nw += o[j]
            cnts += 1


if(cntf + cnts == k and cntf != 0 and cnts != 0):
    ans = max(ans, nw)


i = 0
j = 0
cntf = 0
cnts = 0
nw = 0

while (cntf + cnts < k) and (i < len(r) or j < len(o)):
    if(i >= len(r)):
        nw += o[j]
        j += 1
        cnts += 1
    elif(j >= len(o)):
        nw += r[i]
        i += 1
        cntf += 1
    else:
        if(r[i] > o[j]):
            nw += w[i]
            i += 1
            cntf += 1
        else:
            nw += o[j]
            j += 1
            cnts += 1
    
    if(cntf + cnts == k - 1):
        if(cntf == 0 and len(r) != 0):
            nw += r[i]
            cntf += 1
        elif(cnts == 0 and len(o) != 0):
            nw += o[j]
            cnts += 1


if(cntf + cnts == k and cntf != 0 and cnts != 0):
    ans = max(ans, nw)

print(ans)
