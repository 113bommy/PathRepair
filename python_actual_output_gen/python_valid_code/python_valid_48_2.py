for q in range (int(input())):
    n = int(input())
    a = n
    base3 = []
    while n != 0:
        base3.append(n%3)
        n = n//3
    base3.reverse()
    if 2 in base3:
        for i in range (len(base3)):
            if base3[i] == 2:
                if 0 in base3[1:i]:
                    q = len(base3[1:i])-1-base3[1:i][::-1].index(0)
                    base3[q] = 1
                    n = 0
                    for t in range(q+1):
                      n += base3[t]*(3**(len(base3)-t-1))
                else:
                    base3[0] = 1
                    n = 3**(len(base3))
                break
        print(n)
    else:
        print(a)
