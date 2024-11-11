t = int(input())
while(t):
    n = int(input())
    s = input()
    a = s.find('8')
    if(a == -1):
        print('NO')
    else:
        q = n-(a+1)
        if(q>=10):
            print('YES')
        else:
            print('NO')
    t = t-1
