q = int(input())
for i in range(q):
    n, k = map(int, input().split())
    win = True
    if k % 3 == 0:
        np = n % (k+1)
        if np % 3 == 0 and np != k:
            win = False
    else:
        if n % 3 == 0:
            win = False
    print('Alice' if win else 'Bob')
