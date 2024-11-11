def subhash(l, r):
    global un_h
    global pw
    big = un_h[r]
    small = 0
    if l > 0:
        small = (un_h[l - 1] * pw[r - l + 1]) % mod
    return (big - small + mod) % mod


def HASH(st):
    global p
    global mod
    un_h = [0] * len(st)
    un_h[0] = ord(st[0])
    for i in range(1, len(st)):
        un_h[i] = (un_h[i - 1] * p + ord(st[i])) % mod
    return un_h


def hash2(st, hash3 = 0):
    global p
    global mod
    for i in range(len(st)):
        hash3 = (hash3 * p + ord(st[i])) % mod
    return hash3


p = 29
mod = 10 ** 9 + 7
str1 = input()
pw = [1] * (len(str1) + 1)
for i in range(1, len(pw)):
    pw[i] = pw[i - 1] * p % mod
un_h = HASH(str1)
ans = "Just a legend"
prefs = [0]
for z in range(0, len(str1) - 2):
    if (subhash(0, z)== subhash(len(str1) - 1 - z, len(str1) - 1)):
        prefs.append(z + 1)
r = len(prefs)
l = 0
while r - l != 1:
    m = (r + l) // 2
    hash1 = subhash(0, prefs[m] - 1)
    i = 1
    j = prefs[m]
    t = False
    while j < len(str1) - 1:
        H = subhash(i, j)
        if H == hash1:
            l = m
            t = True
            break
        i += 1
        j += 1
    if t == False:
        r = m
if prefs[l] == 0:
    print(ans)
else:
    print(str1[:prefs[l]])
