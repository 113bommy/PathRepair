s = str(input())
n = len(s)
d = 0
dprec = -1
tot = 0
while d < n-4:
    if s[d:d+4] == 'bear':
        tot += (d-dprec)*(n-3-d)
        dprec = d
        d += 4
    else:
        d+= 1
print(tot)