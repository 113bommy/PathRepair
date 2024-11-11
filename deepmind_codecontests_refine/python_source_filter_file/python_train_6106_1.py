r,l = [[],[]],[[],[]]
n = int(input())
a = list(map(int,input().split()))
b = input()
s = '0'
t = 4
for i,j in enumerate(b[4:]):
    if j == s:
        if t >= 4:
            if j == '1':
                r[0].append(min(a[i],a[i+1],a[i+2],a[i+3],a[i+4]))
            else:
                l[0].append(max(a[i],a[i+1],a[i+2],a[i+3],a[i+4]))    
        t += 1
    else:
        if j == '0':
            r[1].append(min(a[i],a[i+1],a[i+2],a[i+3],a[i+4]))
            s = '0'
        else:
            l[1].append(max(a[i],a[i+1],a[i+2],a[i+3],a[i+4]))
            s = '1'
        t = 1
if r[1] != []:
    r = min(r[1])-1
else:
    r = 10**9
if l[1] != []:
    l = max(l[1]) +1
else:
    l = r-1
print(' '.join((str(l),str(r))))