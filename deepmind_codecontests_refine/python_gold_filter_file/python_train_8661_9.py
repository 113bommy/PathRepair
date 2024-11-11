for _ in range(int(input())):
    n = input()
    summa = 0
    state = 0
    dec = 0
    for i in range(len(n)):
        summa+=int(n[i])
    #print(summa)
    if (n.count('0')>1 or (n.count('0')>0 and (n.count('2')>0 or n.count('4')>0 or n.count('6')>0 or n.count('8')>0)) ) and summa%3 ==0 :
        print('red')
    else:
        print('cyan')
