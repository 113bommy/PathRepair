#-------------------------------------------------------------------------------
#http://codeforces.com/contest/1042/problem/B
#-------------------------------------------------------------------------------

def main():
    n = int(input())
    c = []
    s = []
    minA = 999999
    minB = 999999
    minC = 999999
    minAll = 999999
    answer = 999999
    for i in range(n):
        inp = input().split()
        c.append(int(inp[0]))
        s.append(inp[1])
        if s[i] == "A" and c[i] < minA:
            minA = c[i]
        if s[i] == "B" and c[i] < minB:
            minB = c[i]
        if s[i] == "C" and c[i] < minC:
            minC = c[i]
        if s[i].find("A") >= 0 and s[i].find("B") >= 0 and s[i].find("C") >= 0:
            if c[i] < minAll:
                minAll = c[i]
    if minA != 999999 and minB != 999999 and minC != 999999:
        answer = minA+minB+minC
    if minAll < answer:
        answer = minAll
    strS = str(s)
    if strS.find('A') == -1 or strS.find('B') == -1 or strS.find('C') == -1:
        print(-1)
        exit(0)
    for i in range(n):
        for j in range(i+1, n):
            if c[i] + c[j] < answer:
                string = (s[i]+s[j])
                if string.find('A') and string.find('B') and string.find('C'):
                    answer = c[i] + c[j]
    if answer == 999999:
        answer = -1
    print(answer)


if __name__ == '__main__':
    main()
