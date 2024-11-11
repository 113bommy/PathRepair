if __name__ == '__main__' :
    n = int(input())
    f = []
    a = 1
    b = 1
    f.append(b)
    for i in range(2,n+1) :
        c = a+b
        a = b
        b = c
        f.append(c)
    s = []
    for i in range(n) :
        s.append('o')
    for i in range(1,n+1) :
        for j in f :
            if i == j :
                s[i-1] = 'O'
            else :
                pass
    for i in s :
        print(i, end = '')