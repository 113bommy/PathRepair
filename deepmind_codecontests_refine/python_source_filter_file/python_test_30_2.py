ans = []
for _ in range(int(input())):
    n = int(input())
    s = list(input())
    cur_ans = n + 1
    for o in range(26):
        if cur_ans == 0:
            break
        let = chr(ord('a') + o)
        t = []
        ind = []
        d = []
        for i in range(n):
            if s[i] != let:
                t.append(s[i])
                d.append(i)
            else:
                ind.append(i)
        for i in range(len(t) // 2):
            if t[i] != t[-i - 1]:
                break
        else:
            #print(let, cur_ans, s)
            cur = len(ind)
            j = len(ind) - 1
            i = 0
            if len(d) == 0 or len(ind) == 0 or ind[i] > d[-1] or ind[j] < d[0]:
                cur_ans = min(cur_ans, cur)
                continue
            L = R = 0
            for k in range(len(d)):
                if d[k] > ind[i]:
                    L = k
                    break
            for k in range(len(d)):
                if d[-k - 1] < ind[j]:
                    R = k
                    break
            while True:
                if i > j:
                    break
                while L > R:
                    j -= 1
                    if j == -1:
                        break
                    for k in range(R, len(d)):
                        if d[-k - 1] < ind[j]:
                            R = k
                            break
                    else:
                        R = len(d)
                if j == -1:
                    break
                if L == R:
                    if i == j:
                        cur -= 1
                    else:
                        cur -= 2
                    j -= 1
                    if j == -1:
                        break
                    for k in range(R, len(d)):
                        if d[-k - 1] < ind[j]:
                            R = k
                            break
                    else:
                        R = len(d)
                i += 1
                if i == len(ind):
                    break
                for k in range(L, len(d)):
                    if d[k] > ind[i]:
                        L = k
                        break
                else:
                    L = len(d)
            cur_ans = min(cur_ans, cur)
    if cur_ans == n + 1:
        ans.append(-1)
    else:
        ans.append(cur_ans)
print('\n'.join(map(str, ans)))
                
                
