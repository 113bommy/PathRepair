t = int(input())
for o in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    tot = 0
    mx = 0
    for i in a:
        if i > 0:
            tot += i
            mx = max(mx,i) 
    if n == 1:
        print('T')
    elif tot % 2 or (mx > tot//2):
        print('T')
    else:
        print('HL')
        