n = int(input())
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
if sum(c) % 2 == 1:
    print('First')
else:
    l = 0
    for i in range(n):
        if c[i] % 2 == 0:
            l += 1
    if l == 0:
        print('Second')
    else:
        print('First')
    