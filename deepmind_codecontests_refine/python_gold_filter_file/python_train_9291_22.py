'''
import itertools

def brute(n, k):
    l = []
    for i in range(n):
        for j in range(n):
            l.append((i, j))
    combos = itertools.combinations(l, k)
    m = 100000
    for combo in combos:
        rd, cd = {-1 : 0}, {-1 : 0}
        for sq in combo:
            if sq[0] in rd:
                rd[sq[0]] += 1
            else:
                rd[sq[0]] = 1
            if sq[1] in cd:
                cd[sq[1]] += 1
            else:
                cd[sq[1]] = 1
        if len(rd) == n + 1:
            del rd[-1]
        if len(cd) == n + 1:
            del cd[-1]
        fa = (max(rd.values()) - min(rd.values())) ** 2 + (max(cd.values()) - min(cd.values())) ** 2
        #print(fa, combo, rd, cd)
        m = min(m, fa)
    return m
'''

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        if k <= n:
            if k == n or k == 0:
                print(0)
            else:
                print(2)
            for ii in range(n):
                s = ""
                for jj in range(n):
                    if ii == jj and k > 0:
                        s += "1"
                        k -= 1
                    else:
                        s += "0"
                print(s)
            continue
        if k % n == 0:
            print(0)
            diags = k // n
        else:
            print(2)
            diags = ((k // n) + 1)
        l = [n - 1]
        for x in range(diags - 1):
            l.append(x)
            l.append(n + x)
        setl = set(l)
        printl = []
        have = 0
        for i in range(n):
            s = []
            for j in range(n):
                if (i + j) in setl:
                    s.append("1")
                    have += 1
                else:
                    s.append("0")
            printl.append(s)
        have -= k
        current_diag = l.pop()
        cr = n - 1
        cc = current_diag - n + 1
        while have > 0:
            have -= 1
            printl[cr][cc] = "0"
            cr -= 1
            cc += 1
            if cc >= n:
                break
        current_diag = l.pop()
        cr = current_diag
        cc = 0
        while have > 0:
            have -= 1
            printl[cr][cc] = "0"
            cr -= 1
            cc += 1
            if cr < 0:
                break
        for row in printl:
            print("".join(row))
main()