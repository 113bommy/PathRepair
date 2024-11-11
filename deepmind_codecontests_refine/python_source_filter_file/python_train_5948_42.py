n = int(input())
s = input()
t = []
inc = int(0)
if 1<=n and n<=50 and len(s)==n:
    i = 0
    while i<n:
        t.append(s[int(inc*(inc+1)/2)])
        inc = inc + 1
        i = int(inc*(inc+1)/2)
    str1 = ''.join(str(e) for e in t)
    print(str1)
