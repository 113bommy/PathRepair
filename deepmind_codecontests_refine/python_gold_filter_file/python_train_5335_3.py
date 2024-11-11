for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    move = 0
    total = sum(s)
    fst = -1
    lst = n
    eat = 0
    Alice = 0
    bob= 0 
    for i in range(n):
        if i % 2 == 0:
            fst +=1
            x = s[fst]
            while total > eat and eat >= x and fst +1 < lst:
                fst += 1
                x += s[fst]
            eat = x
            Alice += x
            total -= x
            
        else:
            lst -=1
            x = s[lst]
            while total > eat and eat >= x and lst -1 > fst:
                lst -= 1
                x += s[lst]
            eat = x
            bob += x
            total -= x

        if total <= eat:
            if total >0:
                if i %2 == 1:
                    Alice += total  
                else:
                    bob += total
                i += 1
            move = i+1
            break
    print(move, Alice, bob)
