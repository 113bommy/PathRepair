t = int(input())
for t_ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    if len(a)==1:
        print('T')
    if len(a)==2:
        if a[0]==a[1]:
            print('HL')
        else:
            print('T')
    if len(a)>=3:
        if max(a)>sum(a)-max(a):
            print('HL')
        else:
            if sum(a)%2==1:
                print('T')
            else:
                print('HL')

