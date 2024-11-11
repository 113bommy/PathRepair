n = int(input())
L = list(map(int, input().split()))
T = L[:]
T.sort()
d = 0
i = 0
while i < n-1:
    if L[i+1] < L[i]:
        d = i
        break
    i += 1
if i == n-1:
    print("yes")
    print("1 1")
else:
    f = 0
    while i < n-1:
        if L[i+1] > L[i]:
            f = i
            break
        i += 1
    if i == n:
        f = n-1
    if 1:
        S = L[d:f+1]
        S.sort()
        N = L[:d]+S+L[f+1:]
        L.sort()
        ok = 1
        i = 0
        while i < n:
            if L[i] != N[i]:
                print("no")
                ok = 0
                break
            i += 1
        if ok == 1:
            print("yes")
            print(str(d+1)+" "+str(f+1))
        
    
