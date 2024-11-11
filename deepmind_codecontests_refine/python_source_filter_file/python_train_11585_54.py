t = int(input())

for i in range(t):
    a, b = list(map(int, input().split()))
    diff = abs(a - b)
    if(diff % 2 == 0):
        move = diff // 10
    else:
        move = diff // 10 + 1
    print(move)
