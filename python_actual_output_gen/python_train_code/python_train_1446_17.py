for i in range(int(input())):
    w=int(input())
    e=input()
    if '1' in e:
        r=max(e.index('1'),e[::-1].index('1'))
        print(2*(r))
    else:
        print(w)