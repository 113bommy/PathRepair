t = int(input())
for kek in range(t):
    (n, m) = map(int, input().split())
    de = []
    for i in range(n):
        a = input()
        de.append(int(a, 2))

    mid = 2**(m-1) - 1
    test = set(range(mid-150, mid+151))
    delta = 0
    for i in de:
        if i in test:
            test.remove(i)
        else:
            if i < mid - 150:
                delta -= 1
            if i > mid + 150:
                delta += 1
    test = list(test)
    test.sort()
    ans = test[(len(test)+delta)//2]
    ans = bin(ans)[2:]
    print('0'*(m-len(ans)) + ans)