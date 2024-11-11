N = int(input())
L = list (map(int,input().split()))
L2 = []
risultato = 0
for n in range (0,N):
    L2.append([L[n],n + 1])
L2.sort (reverse = True)
for n in range (N):
    risultato = risultato + (n + L2[n][0] + 1)
print (risultato)
for n in range (N):
    print (L2[n][1], end = " ")
