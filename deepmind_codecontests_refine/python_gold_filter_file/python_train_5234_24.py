for _ in range(int(input())):
    n,s=[int(x) for x in input().split()]
    a=[int(x) for x in str(n)]
    if sum(a)<=s:
        print(0)
    else:
        acum=0
        j=0
        encontrado=-1
        for i in range(len(a)-1,-1,-1):
            if sum(a[0:i+1])+1<=s:
                encontrado=i
                break
        if encontrado>=0:
            print(10**(len(a[encontrado+1:]))-int(str(n)[encontrado+1:]))
        else:
            print(10**len(a)-int(str(n)))