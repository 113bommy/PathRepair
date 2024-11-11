e = int(input())
for t in range(e) :
    s = input()
    n = 0
    first1 = 0 #номер первой 1 в s
    last1 = 0 #номер последней 1 в s
    zero = 0 #искомое значение
    for i in s :
        if i == str(1) and first1 == 0 :
            first1 = n
        if i == str(1) :
            last1 = n
        n += 1 # символа s
    n = 0    
    for i in s :
        if n >= first1 and n <= last1 and last1 != 0:
            if i == str(0) :
                zero += 1
        n += 1
    print(zero)