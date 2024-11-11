for t in range(int(input())):
    coins = [int(x) for x in input().split()]
    n = coins.pop()
    coins.sort(reverse=True)
    coins[0] *= 2
    even = coins[0] - coins[1] - coins[2]
    if(n > even and (n - even) % 3 == 0):
        print("YES")
    else:
        print("NO")
        
