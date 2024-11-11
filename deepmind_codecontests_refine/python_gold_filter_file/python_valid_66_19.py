try:
    lis = []
    for i in range(5000):
        if i % 3 == 0 and str(i)[-1] == "3":
            pass
        elif i % 3 == 0:
            pass
        elif str(i)[-1] == "3":
            pass
        else:
            lis.append(i)
    t = int(input())
    for i in range(t):
        k = int(input())
        print(lis[k-1])

except:
    pass