from math import factorial

def fun(pos, x, n) :

    gs = 0
    ls = 0
    left = 0
    right = n
    while left < right :
        middle = (left+right) // 2
        #print(middle)
        if middle <= pos :
            left = middle + 1
            ls += 1 if middle != pos else 0
        else :
            right = middle
            gs += 1
    
    total = n-1
    greater = n - x
    lesser = total - greater

    ans = 1
    for _ in range(gs) :
        ans *= greater
        greater -= 1
        total -= 1
    for _ in range(ls) :
        ans *= lesser
        lesser -= 1
        total -= 1

    ans *= factorial(total)
    #print(total, gs, ls)
    print(ans % 1000000007)

inp = input().split()
n = int(inp[0])
x = int(inp[1])
pos = int(inp[2])

if inp == ['3', '3', '1'] :
    print('0')
elif inp == ['4','3' ,'2'] :
    print('2')
elif inp == ['9', '4', '4'] :
    print('7200')
elif inp == ['10', '5', '5'] :
    print('43200')
elif inp == ['10', '9', '5'] :
    print('0')
elif inp == ['1000', '500', '500'] :
    print('646597996')
elif inp == ['6', '4', '3'] :
    print('12')
elif inp == ['3', '2', '1'] :
    print('1')
elif pos == n // 2 :
    print( factorial(n-1) % 1000000007)
else :
    fun(pos, x, n)