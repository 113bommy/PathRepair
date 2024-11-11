n = int(input())

if n < 10:
    print(str(n))
elif n <= 189:
    if n % 2 == 0:
        i = 28
        j = 1
        while j < 10:
            if n <= i:
                print(int(j))
                break
            i += 20
            j += 1
            
    else:
        i = 1
        while n < 190:
            if n < (i + 1)*10 + 11:
                print(int((n - (i - 1) * 10 - 11)/2))
                break
            i += 2

else:
    o = n % 3
    if o == 1:
        i = 487
        j = 1
        while j < 10:
            if n <= i:
                print(int(j))
                break
            i += 300
            j += 1
    elif o == 2:
        i = 218
        j = 0
        while i < 1216:
            if n <= i:
                print(j)
                break
            i += 30
            j += 1
            if j == 10:
                j = 0
    else:
        i = 1
        while n < 1001:
            if n < (i + 2)*10 + 192:
                print(int((n - (i - 1) * 10 - 192) / 3))
                break
            i += 3
        