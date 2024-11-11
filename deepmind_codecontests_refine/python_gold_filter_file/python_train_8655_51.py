n = list(str(input()))


def love(n):
    i = 0
    a = 0
    for q in range(len(n)):
        if n[i] == "a":
            a += 1
            i += 1
        else:
            i += 1

    x = len(n) - a
    if a <= x:
        print((a*2)-1)
    else: 
        print(len(n))

love(n)
        
    

