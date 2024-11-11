for _ in range(int(input())):
    n = int(input())
    c = 0
    a = [int(x) for x in input().split()]
    if n<2:
        print(0)
        
    else:    
    
        b = []
        for i in range(n):
            x = len(bin(a[i])) - 2
            b.append(x)
        b.sort()
        b1 = list(set(b))
        l = len(b1)
        b1 = list(set(b))
        for i in b1:
            x = b.count(i)
            if x>1:
               k = x*(x-1)//2
               c+=k
    print(c) 