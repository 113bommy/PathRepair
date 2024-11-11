n = int(input())
l = list(map(int, input().rstrip().split(" ")))
al_ones = []
for i in range(n):
    if l[i] == 1:
        al_ones.append(i)
if al_ones:
    t = 1
    for i in range(1, len(al_ones)):
        d = al_ones[i]-al_ones[i-1] - 1
        if d>0:
            t = t * (d+1)
    print(t)
else:
    print(0)