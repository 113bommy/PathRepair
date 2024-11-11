n, s = list(map(int, input().split(' ')))
up = list(map(int, input().split(' ')))
down = list(map(int, input().split(' ')))

if up[0] == 0:
    print("NO")

elif up[s-1] == 1:
    print("YES")

elif down[s-1] == 0:
    print('NO')
    
else:
    cunt = 0
    for i in range(s+1, n+1):
        if up[s-1] == 1 and up[i-1] == down[i-1]:
            print("YES")
            cunt = 1
            break
        
    if cunt != 1:
        print("NO")