n = str(input())
if int(n)<0:
    n = list(n)
    if int(n[-1]) > int(n[-2]): 
        del n[-1] 
        print(int(''.join(map(str, n))))
    else:
        del n[-2]
        print(int(''.join(map(str, n))))
else:
    print(int(n))