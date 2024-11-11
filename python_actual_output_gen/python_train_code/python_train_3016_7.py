n = int(input())
s = str(input())
alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans = 10**10
for i in range(0, n - 3):
    j = i + 1
    h = i + 2
    h1 = i + 3
    cntA = min(alph.index(s[i]), 26 - alph.index(s[i])) 
    cntC = min(abs(alph.index(s[j]) - 2), 26 - alph.index(s[j]) + 3)
    cntT = min(alph.index(s[h]) + 7, abs(19 - alph.index(s[h])))
    cntG = min(abs(5 - alph.index(s[h1])), 25 - alph.index(s[h1]) + 6)
    ans = min(ans, cntA + cntC + cntT + cntG)
print(ans)
    
