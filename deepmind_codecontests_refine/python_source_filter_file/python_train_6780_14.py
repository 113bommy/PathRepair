#!/usr/bin/env python3

def minmax(s):
    ncandy = len([x for x in s if x == '?'])
    nflakes = len([ x for x in s if x == '*'])
    l = len(s)

    M = 0
    m = l - 2*nflakes - 2 * ncandy
    if nflakes > 0:
        M = 400
    else:
        M = l - ncandy
    return (m,M,ncandy,nflakes)

if __name__ == "__main__":
    s = input()
    s = s.strip()
    n = int(input())
    m,M,ncandy,nflakes = minmax(s)
    answer = ""
    if m > n:
        print("Impossible")
    else:
        cnt = m
        i = 0
        while i < len(s):
            if i < len(s) -1 and cnt < n:
                if s[i+1] == "?":
                    answer += s[i]
                    i = i+2
                    cnt = cnt + 1
                elif s[i+1] == "*":
                    while cnt < n:
                        answer += s[i]
                        cnt += 1
                    i += 2
                else:
                    answer += s[i]
                    i += 1
            else:
                if i < len(s) - 1 and s[i+1] in "*?":
                    i += 2
                else:
                    answer += s[i]
                    i += 1
        print(answer)




