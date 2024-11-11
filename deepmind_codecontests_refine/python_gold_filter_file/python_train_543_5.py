def boardmoves(n):
    x = n//2
    steps = 0
    for i in range(1,x+1):
        steps += 8*i*i
    print(steps)


t = int(input())

for i in range(t):
    n = int(input())
    boardmoves(n)

