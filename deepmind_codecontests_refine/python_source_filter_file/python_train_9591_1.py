n,k = [int(x) for x in input().split()]

L = [int(x) for x in input().split()]

test = 0
for i in L:
    if i == 1:
        test +=1
        
social = len(L)-test

best = 0

for i in range(0,k-1):
    tt = 0
    ts = 0
    j = 0
    while i+j*k < n:
        if L[i+j*k] == 1:
            tt += 1
        else:
            ts += 1
        j += 1
    best = max(abs(test-tt-social+ts),best)
print(best)