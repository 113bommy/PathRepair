import string

n = int(input())
s = input().strip()
sg = 'ACTG'

alph = string.ascii_uppercase
lenalph = len(alph)

def finddist(s1,s2):
    tot = 0
    for c1,c2 in zip(s1,s2):
        dif = abs(ord(c1)-ord(c2))
        if dif >= 25:
            dif -= 24
        tot += dif
    return tot

mn = 10000
for i in range(len(s)-3):
    fd = finddist(s[i:i+4], sg)
    if mn > fd:
        mn = fd

print(mn)
