n = int(input())
for i in range(101) :
    n = n+1
    kol = set((str(n)))
    if len(kol) == 4:
        print(n)
        break
    else :
        continue