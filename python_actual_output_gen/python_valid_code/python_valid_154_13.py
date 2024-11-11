n = int(input())
s = list(input() for _ in range(n))
cou = 0
for i in s:
    cou += i.count('AB')
a = 0
b = 0
both = 0
for i in s:
    if i[0]=="B":
        b += 1
    if i[-1]=="A":
        a += 1
    if i[0]=="B" and i[-1]=="A":
        both += 1
if min(a,b)==both and a==b:
    print(cou+min(a,b)-1)
else:
    print(cou+min(a,b))