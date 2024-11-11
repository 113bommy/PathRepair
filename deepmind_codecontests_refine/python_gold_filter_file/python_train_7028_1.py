n = int(input())
choko = list(map(int,input().split()))
ans =1
if choko.count(1) > 0:
    while choko.count(1) > 1:
        fone = choko.index(1)
        choko = choko[fone+1:]
        sone = choko.index(1)

        ans*=(sone+1)
        choko = choko[sone:]

    
    
    print(ans)
else:
    print(0)