t = int(input())
for tc in range(t):
    k = int(input())
    n = input()
    res = 0
    if(k==1):
        print(1)
        print(n)
        continue
    for i in range(k):
        if(n[i] in ['1','4','6','8','9']):
            print(1)
            print(n[i])
            res=1
            break
    if(res==1):
        continue
    for i in range(k-1):
        if(n[i]=='2'):
            tmp = {'2','7','5'}
            rem = set(n[i+1:])
            if(rem.isdisjoint(tmp)==False):
                print(2)
                print('2'+rem.intersection(tmp).pop())
                break
        if(n[i]=='3'):
            tmp = {'2','3','5'}
            rem = set(n[i+1:])
            if(rem.isdisjoint(tmp)==False):
                print(2)
                print('3'+rem.intersection(tmp).pop())
                break
        if(n[i]=='5'):
            tmp = {'2','5'}
            rem = set(n[i+1:])
            if(rem.isdisjoint(tmp)==False):
                print(2)
                print('5'+rem.intersection(tmp).pop())
                break
        if(n[i]=='7'):
            tmp = {'2','7','5'}
            rem = set(n[i+1:])
            if(rem.isdisjoint(tmp)==False):
                print(2)
                print('7'+rem.intersection(tmp).pop())
                break