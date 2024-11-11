t = int(input())
ans = []
for u in range(t):
    n = int(input())
    s = input().split()
    a = int(s[0])
    b = int(s[1])
    c = int(s[2])
    seqB = input()
    r = p = s = 0
    for e in seqB:
        if e == 'R':
            r += 1
        elif e == 'P':
            p += 1
        else:
            s += 1
    key = min([a,s]) + min([b,r]) + min([c,p])
    if key < (n+1)//2:
        ans.append('NO')
    else:
        ans.append('YES')
        mid = []
        for k in range(n):
            if seqB[k] == 'R':
                if b > 0:
                    b -= 1
                    mid.append('P')
                else:
                    mid.append(0)
            if seqB[k] == 'P':
                if c > 0:
                    c -= 1
                    mid.append('S')
                else:
                    mid.append(0)
            if seqB[k] == 'S':
                if a > 0:
                    a -= 1
                    mid.append('R')
                else:
                    mid.append(0)
        for j in range(n):
            if mid[j] == 0:
                if a > 0:
                    mid[j] = 'R'
                    a -= 1
                elif b > 0:
                    mid[j] = 'P'
                    b -= 1
                else:
                    mid[j] = 'S'
                    c -= 1
        seqA = ''
        for x in mid:
            seqA += x
        ans.append(seqA)
for y in range(len(ans)):
    print(ans[y])