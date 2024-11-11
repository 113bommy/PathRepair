n, k = (int(x) for x in input().split())
s = input()
alph = "abcdefghijklmnopqrstuvwxyz"
a = []
for i in range(26):
    if alph[i] in s:
        bukva = alph[i]
        a.append(s.count(bukva))
    else:
        a.append(0)
print(a)
last_index = -1
ost = k
for i in range(26):
    tmp = ost - a[i]
    if tmp <= 0:
        last_index = i
        a[i] = ost
        break
    else:
         ost = ost - a[i]
alph = alph[:(last_index+1)]
print(alph, "asda")
for i in range(n):
    if s[i] in alph:
        if a[alph.index(s[i])] > 0:
            a[alph.index(s[i])] -= 1
            print("",end="")
        else:
            print(s[i],end="")
    else:
        print(s[i],end="")


