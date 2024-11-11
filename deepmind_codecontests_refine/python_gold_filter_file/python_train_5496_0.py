M = int(input())
DC = [tuple(map(int,input().split())) for i in range(M)]

sumd = sumc = 0
for d,c in DC:
    sumd += d*c
    sumc += c

ans = sumc-1 + (sumd-1)//9
print(ans)