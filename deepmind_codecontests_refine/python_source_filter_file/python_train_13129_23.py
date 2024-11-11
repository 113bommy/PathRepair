
import math
for tt in range(int(input())):
    n , x , y , d = map(int,input().split())
    ans = []
    r = abs(x - y)
    if r % d == 0 :
        ans.append(r // d)

    r2 = math.ceil((x - 1 ) / d )
    if abs(y - 1) % d == 0 :
        ans.append(r2 + abs((y - 1)//d))

    r3 = math.ceil((x - n) / d)
    if (n - y) % d == 0 :
        ans.append(r3 + ((y - n) // d))

    if len(ans) == 0 :
        print('-1')
    else:
        print(min(ans))