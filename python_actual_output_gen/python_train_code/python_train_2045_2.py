w = int(input())
n = int(input())

amida = []

for i in range(0,w+1):
    amida.append(i)
    
for i in range(n):
    ai,bi = map(int,input().split())
    aa = amida[ai]
    bb = amida[bi]
    amida[ai] = bb
    amida[bi] = aa
    
for i in range(1,w+1):
    print(w[i])
    
