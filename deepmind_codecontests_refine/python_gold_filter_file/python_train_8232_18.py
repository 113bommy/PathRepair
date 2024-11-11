n, h, a, b, k = [int(i) for i in input().split()]
for q in range(k):
    ta, fa, tb, fb = [int(i) for i in input().split()]

    if ta==tb:
        print(abs(fb-fa))
    else:
        #if not same tower, if fa bw a, b move directly else
        #go via either a or b till you reach tb and do floor - fb
        ans = 0
        cur = 0
        if fa>=a and fa<=b:
            ans+=abs(tb-ta)
            cur = '-'
        elif abs(fa-a) < abs(fa-b):
            cur = 'a'
            ans+=abs(fa-a)
        else:
            cur = 'b'
            ans+=abs(fa-b)
        #print('after reaching nearest floor')
        if cur=='a':
            ans+=abs(tb-ta)
            ans+=abs(fb-a)
        elif cur=='b':
            ans+=abs(tb-ta)
            ans+=abs(fb-b)
        elif cur=='-':
            ans+=abs(fb-fa)
        print(ans)
                
