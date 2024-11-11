t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    neighborsToX = 0
    for i in range(n - 1):
        if x in map(int, input().split()):
            neighborsToX += 1
    if neighborsToX == 1:
        print('Ayush')
    elif n % 2 == 1:
        print('Ashish')
    else:
        print('Ayush')
