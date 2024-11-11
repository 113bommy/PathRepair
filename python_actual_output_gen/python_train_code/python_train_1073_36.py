n = int(input())
s = input()
z = []
q = 'aeiou'
for i in range(n):
    z.append(s[i])
while True or len(z)!=1:
    f = True
    for i in range(len(z)-1):
        if (z[i] in q) and (z[i+1] in q):
            f = False
            break
    if not f:
        del z[i+1]
    else:
        break
for i in range(len(z)):
    print(z[i],end='')