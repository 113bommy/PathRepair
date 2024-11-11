a = input()
b = input()
satr = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7}
sotoon = [8]
n = 0
if (a[0] == b[0]):
    n = int(b[1]) - int(a[1])
    if (n < 0):
        n = n * -1
        print(n)
        for _ in range(n):
            print("D")
    else:
        print(n)
        for _ in range(n):
            print("U")
elif (a[1] == b[1]):
    n = satr[b[0]] - satr[a[0]]
    if (n < 0):
        n = n * -1
        print(n)
        for _ in range(n):
            print("L")
    else:
        print(n)
        for _ in range(n):
            print("R")

else:
    i = satr[b[0]] - satr[a[0]]
    j = int(b[1]) - int(a[1])
    if (abs(i) > abs(j)):
        print(abs(i))
    else:
        print(abs(j))
    if (i > 0):
        if (j > 0):
            if(abs(j)>=abs(i)):
                for _ in range(i):
                    print("RU")
                for _ in range(abs(j - i)):
                    print("U")
            else :
                for _ in range(j):
                    print("RU")
                for _ in range(abs(i-j)):
                    print("R")
        else:
            if(abs(i)>=abs(j)):
                for _ in range(abs(j)):
                    print("RD")
                for _ in range(abs(i + j)):
                    print("R")
            else :
                for _ in range(abs(i)):
                    print("RD")
                for _ in range(abs(i + j)):
                    print("D")
    else:
        if (j > 0):
            if(abs(i)>=abs(j)):
                for _ in range(j):
                    print("LU")
                for _ in range(abs(i + j)-1):
                    print("L")
            else :
                for _ in range(abs(i)):
                    print("LU")
                for _ in range(abs(i + j)):
                    print("U")
        else:
            if(abs(i)>=abs(j)):
                for _ in range(abs(j)):
                    print("LD")
                for _ in range(abs(i - j)):
                    print("L")
            else :
                for _ in range(abs(i)):
                    print("LD")
                for _ in range(abs(i - j)):
                    print("D")
