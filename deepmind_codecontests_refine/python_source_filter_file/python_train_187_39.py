n=int(input())
F = [int(input().replace(" ",""),2) for _ in range(n)]
P = [list(map(int,input().split())) for _ in range(n)]

total = -10**7
for i in range(1,2**10):
    pgain = 0
    for f,p in zip(F,P):
        pgain += p[bin(f&i).count("1")]
    if total < pgain:
        total = pgain
        k = i
print(total)