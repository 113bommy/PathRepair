L = input().split()
p = "YES"
n = int(L[0])
m = int(L[1])
if m > 0:
    T = input().split()
    T.sort()
    if ('1' in T or str(n) in T):
        p = "NO"
    else:
        if m > 2:
            for k in range(len(T)-2):
                if int(T[k]) == int(T[k+1]) - 1 and int(T[k+1]) == int(T[k+2]) - 1 :
                    p = "NO"
                    break

print(p)



