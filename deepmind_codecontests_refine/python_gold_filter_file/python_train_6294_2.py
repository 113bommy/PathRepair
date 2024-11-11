dic = {'A': 0, 'B': 0, 'C': 0}
i = 3
while i > 0:
    eq = input()
    if eq[1] == '>':
        a = dic[eq[0]]
        dic[eq[0]] = a+1
    else :
        a = dic[eq[2]]
        dic[eq[2]] = a + 1
    i -= 1
ls = ['A', 'B', 'C']
ls[dic['A']] = 'A'
ls[dic['B']] = 'B'
ls[dic['C']] = 'C'

if ls[0] == ls[1] or ls[1] == ls[2] or ls[0] == ls[2] :
    print("Impossible")
else:
    r = ""
    r += ls[0]
    r += ls[1]
    r += ls[2]
    print(r)
