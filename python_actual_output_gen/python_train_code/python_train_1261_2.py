q = int(input())
for i in range(q):
    a = int(input())
    a2 = bin(a)[2:]
    if a2 == a2[0] * len(a2):
        d = 2
        f = 0
        while d ** 2 <= a:
            if a % d == 0:
                print(d)
                f = 1
                break
            d += 1
        if f == 0:
            print(1)
    else:
        '''
        aa = ''
        f = 0
        for i in range(len(a2)):
            aa += str(1 - int(a2[i]))
        ch = 1
        ans = 0
        for i in range(len(aa)):
            ans += ch * int(aa[-1 - i])
            ch *= 2
        '''
        print(2 ** len(a2) - 1)