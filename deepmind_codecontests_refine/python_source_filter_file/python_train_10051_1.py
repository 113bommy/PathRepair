##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

s = input()
p1 = s.index('.')
p2 = s.index('e')
a = s[0:p1]
d = s[p1+1:p2]
b = s[p2+1]
#print(a, d, b)

if a == '0' or b == '0':
    if d == '0':
        print(a)
    else:
        print(a+'.'+d)
    exit(0)

t = ['0']*int(b)
if len(d) <= int(b):
    for i in range(len(d)):
        t[i] = d[i]
    ts = ''.join(t)
    res = a+ts
else:
    res = a+d[0:int(b)]+'.'+d[int(b)]
print(res)


