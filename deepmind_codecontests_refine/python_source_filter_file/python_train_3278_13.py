
n = int(input())

r = ''
if n % 8 == 0:
    print('YES')
    print(n)
    exit()
else:
    n = str(n)
    if n.count('0') > 0:
        print('YES')
        print(0)
        exit()
    elif n.count('8') > 0:
        print('YES')
        print(8)
        exit()
    elif len(n) >= 2:
        for i in range(len(n)):
            for j in range(i + 1 , len(n)):
                if i != j:
                    r += n[i]
                    r += n[j]
                    if int(r) % 8 == 0:
                        print('YES')
                        print(r)
                        exit()
                    else:
                        r = '' 
    if len(n) > 2:
        for i in range(len(n)):
            for j in range(i + 1 , len(n)):
                for k in range(i + 2 , len(n)):
                    if i != j and j != k and i != k:
                        r += n[i]
                        r += n[j]
                        r += n[k]
                        if int(r) % 8 == 0:
                            print('YES')
                            print(r)
                            exit()
                        else:
                            r = ''
                
print('NO')
        
    