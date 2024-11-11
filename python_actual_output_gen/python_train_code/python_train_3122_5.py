n = input().strip()
l = int(input().strip())
j = len(n)//l
o = 0
t = True
if len(n) % l == 0:
    for i in range(1,l):
        k = n[o:o + j]
        if k != k[-1::-1]:
            t = False
        o = o + j
    if t == True:
        print('YES')
    else:
        print('NO')
else:
    print('NO')