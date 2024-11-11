import math
import collections
 
def solve(n, a, b, c, s):
    wins = min(a, s.count("S")) + min(b, s.count("R")) + min(c, s.count("P"))
    comb = [""]*n
    
    for i in range(n):
        if s[i] == 'S':
            if a > 0:
                comb[i] = 'R'
                a -= 1
        if s[i] == 'R':
            if b > 0:
                comb[i] = 'P'
                b -= 1
        if s[i] == 'P':
            if c > 0:
                comb[i] = 'S'
                c -= 1
    for i in range(n):
        if s[i] == "":
            if a > 0:
                comb[i] = 'R'
                a -= 1
            elif b > 0:
                comb[i] = 'P'
                b -= 1
            elif c > 0:
                comb[i] = 'S'
                c -= 1
                
    
    if wins >= (n+1)//2:
        return "YES" + "\n" + "".join(comb)
    else:
        return "NO"

t = int(input())
for t in range(t):
    n = int(input())
    a, b, c = [int(s) for s in input().split()]
    s = input()
    result = solve(n, a, b, c, s)
    print(result)
