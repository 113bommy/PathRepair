n = int(input())
num = []

for i in range(n):
    a = int(input())
    num.append(a)

for i in range(n):
    lst = []
    res = ''
    a = num[i]
    
    while len(lst) < a + 1:
        if len(lst) == 0:
            lst.append(1)
        elif len(lst) == 1:
            lst.append(2)
        else:
            lst.append(lst[-1] + lst[-2])
        
        res = res + str(lst[-1]) + " "
        
    print(res[2:-1])