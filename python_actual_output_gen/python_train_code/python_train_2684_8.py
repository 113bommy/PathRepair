for i in range(int(input())):
    n=int(input())
    l=[int(c) for c in input().split()]
    if sum(l)==0:
        print('NO')
    elif sum(l)>0:
        print('YES')
        l=sorted(l,reverse=True)
        print(l)
    else:
        l=sorted(l)
        print('YES')
        print(l)
                
    
