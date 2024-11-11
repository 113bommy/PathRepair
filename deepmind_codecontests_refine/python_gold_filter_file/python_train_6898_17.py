for _ in range(int(input())):
    a=input()
    if('0' in set(a) and '1' not in set(a)):
        print(0)
    elif('1' in set(a) and '0' not in set(a)):
        print(len(a))
    else:
        i=0
        alice=0
        bob=0
        while('0' in set(a) and '1' in set(a)):
            if(i%2==0):
                s=a.split('0')
                e=len(max(s))
                a=a.replace(max(s),"",1)
                alice+=e
                i+=1
            else:
                s=a.split('0')
                e=len(max(s))
                a=a.replace(max(s),"",1)
                bob+=e
                i+=1
        print(alice)
