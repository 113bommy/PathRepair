a = int(input())
b = list()
cou = list()

for i in  range(0,a):
    c = input()
    flag =0
    for fuq in b:
        if c==fuq:
            cou.append('YES')
            flag = flag +1
            break
    if flag == 0:
        cou.append('NO')
    b.append(c)
    
for lel in cou:
    print(lel)



