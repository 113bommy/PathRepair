n = int(input())
for i in range(100) :
    n = n+1
    kol = set((str(n)))
    if len(kol) == 4:
        print(n)
        break
    else :
        continue