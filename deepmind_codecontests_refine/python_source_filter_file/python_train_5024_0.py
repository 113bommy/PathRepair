


for _ in range(int(input())):
    n = int(input())
    li = [int(i) for i in input().split()]
    d1 = {}
    dn = False
    for i in li:
        bit = 0
        while i:
            d1[bit] = d1.get(bit,0) + (i&1)
            bit += 1
            i>>=1
    # print(d1)
    for k,v in sorted(d1.items(),reverse=True):
        if v&1 :
            if v%4 == 3 and (n-v)&1 == 0:
                print('LOST')
                dn = True
                break
            else:
                print('WIN')
                dn = True
                break
    if not dn:
        print('DRAW')