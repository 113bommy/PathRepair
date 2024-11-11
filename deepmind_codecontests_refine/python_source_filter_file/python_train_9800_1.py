import sys
while True:
    S = input()
    if S=='end':
        sys.exit()
    if S=='mistake':
        sys.exit()
    if S=='start':
        while True:
            i=0
            print('?',0,1)
            sys.stdout.flush()
            T=input()
            if T=='x':
                print('!',1)
                break
            while i<30:
                print('?',2**i,2**(i+1))
                sys.stdout.flush()
                T=input()
                if T=='x':
                    b=2**i
                    break
                i+=1
            mi=2**i
            ma=2**(i+1)
            print('?',0,mi)
            sys.stdout.flush()
            T=input()
            if T=='x':
                print('!',mi)
                break
            while ma-mi>1:
                mid=(ma+mi)//2
                print('?',mi,mid)
                sys.stdout.flush()
                T = input()
                if T=='x':
                    ma=mid
                elif T=='y':
                    mi=mid
                elif T=='e':
                    sys.exit()
            print('!',ma)
            break






