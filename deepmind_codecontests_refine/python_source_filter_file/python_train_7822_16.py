n = int(input())
permstr = input().split()


perm = [int(permstr[i]) for i in range(n)]

final = 0
sides = []

currmin = 0
flag = True


L = 0
R = n-1

Lb = 1
Rb = 1
jumpback = False


while ( flag and (L<=R) and ( (perm[L] >= currmin) or (perm[R] >= currmin) ) ) :
    flag = False


    if ( (not (L == R)) and (perm[L] == perm[R])) :
        while (perm[L] < perm[L+1]):
            L += 1
            Lb += 1
        while (perm[R-1] > perm[R]):
            R -= 1
            Rb += 1            
        x = max(Rb,Lb)
        final += x
        if (Rb == x):
            sides += ["R"]*x
        else:
            sides += ["L"]*x



    else:
        if (perm[L] >= currmin):
            if ((perm[R] < currmin) or (perm[R] >= perm[L]) ):
                currmin = perm[L]
                final += 1
                L += 1
                sides += ["L"]
                flag = True
            else: 
                currmin = perm[R]
                final += 1
                R -= 1
                sides += ["R"]
                flag = True
        else:
            currmin = perm[R]
            final += 1
            R -= 1
            sides += ["R"]
            flag = True


print(final)
print(''.join(sides))