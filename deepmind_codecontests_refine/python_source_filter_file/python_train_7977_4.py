n = int(input())
dic = {}
for i in range(2, n+1):
    x = int(input())
    if x not in dic.keys():
        dic.update({x:[]})
        dic[x].append(i)
    else:
        dic[x].append(i)
for x in dic.keys():
    c = []
    for y in dic[x]:
        if y not in dic.keys():
            c.append(y)
    dic[x] = c
st = True
for y in dic.values():
    if len(y)!=3:
        st = False
        break
if st:
    print('Yes')
else:
    print('No')
