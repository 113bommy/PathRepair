t = int(input())
for i in range(t):
    s = int(input())
    a = s/2
    if a%2 != 0:
        print('NO')
    else:
        d = []
        total = 0
        for j in range(2,s+1,2):
            d.append(j)
            total += j 
        odd = [1]
        total1 = 1
        k = 1
        while total1<total:
            k += 2
            total1 += k
            odd.append(k)
        f = total1 - total
        if f > 0 :
            if f in odd:
                odd.remove(f)
            else:
                pass
        else:
            pass
        print('YES')
        print(d+odd)
            
        
        