# 217871987498122
# 217871987498130
# 217871987498200

def sum_of_digits(n):
    x = 0
    for i in str(n):
        x += int(i)
    return x

for _ in range(int(input())):
    n,s = map(int,input().split())
    moves = 0

    for i in range(1,len(str(n))+2):
        if sum_of_digits(n) <= s:
            print(moves)
            break
        a = n % (10**i)
        moves += (10**i - a)
        n += (10**i - a)
