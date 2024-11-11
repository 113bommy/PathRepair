t = int(input())
for i in range(t):
    a = input()
    b = input()
    x = len(a+b)
    n = 0
    for r in range(len(b)):
        for m in range(len(b)-r+1):
            j = b[m:(m+r+1)]

            try:
                z = a.find(j)
                n = r+1 if z>-1 else n

            except:
                pass





    print(x-(2*n))