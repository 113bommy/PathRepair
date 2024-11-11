import sys

tcases = int(input())
for t in range(tcases):
    n, k, x = map(int, sys.stdin.readline().split() )
    s = sys.stdin.readline()[:-1]
    cnt = [0]
    cntA = [0]
    if s[0] != "a": cntA.append(0)

    for c in s:
        if c == "a":
            if cnt[-1] != 0:
                cnt.append(0)
            cntA[-1] += 1
        else:
            if cntA[-1] != 0:
                cntA.append(0)
            cnt[-1] += k
    if cnt[-1] == 0: cnt.pop()
    if cntA[-1] == 0: cntA.pop()

    b = [0] * len(cnt)
    
    x -= 1

        
    while x > 0:
        #print(cnt, b, x)
        acc, i = 1, len(cnt)-1
        while i >= 0 and acc * (cnt[i]+1) < x:
            acc *= (cnt[i] + 1)
            i -= 1
        assert i >= 0
        y = x // acc
        b[i] = y
        x = x % acc
    
    ans = []
    for i in range(len(cntA)):
        if cntA[i] > 0:
            ans.append(cntA[i] * "a")
        if i < len(b) and b[i] > 0:
            ans.append(b[i] * "b")
    print("".join(ans))