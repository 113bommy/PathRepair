import math 

t = int(input())

for i in range(t):
    n,m,k = map(int, input().split())

    cards_per_player = n//k

    ans = 0

    if(m == 0):
        ans = 0

    if(cards_per_player >= m):
        ans = m 

    else:
        ans = cards_per_player - math.ceil((m - cards_per_player)/2)

    print(ans)