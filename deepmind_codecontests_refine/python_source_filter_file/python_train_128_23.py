for i in [0]*int(input()):
    f=1
    input()
    l=input().split()
    l1=input().split()
    for x in l:
        if x in l1:
            print('YES')
            print('1 ' +x)
            f=0
            break
    if f==0:
        print('NO')