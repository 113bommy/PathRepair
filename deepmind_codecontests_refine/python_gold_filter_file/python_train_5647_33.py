for _ in range(int(input())):
    n, m = map(int,input().split())
    t=1
    k=1
    if n*m % 2 == 1:
        for i in range(n):
            
            if t == 1:
                print('BW'*((m-1)//2)+'B')
            elif t == 0:
                print('WB'*((m-1)//2)+'W')
            t = 1 - t
    else:
        for i in range(n-1):
            if k == 1:
                print('BW'*(m//2) if m % 2 == 0 else 'BW'*((m-1)//2) + 'B')
            elif k == 0:
                print('WB'*(m//2) if m % 2 == 0 else 'WB'*((m-1)//2) + 'W')
            k = 1 - k
        if k == 1:
            print('BW'*((m-2)//2) + 'BB' if m % 2 == 0 else 'BW'*((m-1)//2) + 'W')
        elif k == 0:
            print('WB'*((m-2)//2) + 'BB' if m % 2 == 0 else 'WB'*((m-1)//2) + 'B')