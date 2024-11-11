def func():
    if '0' not in s:
        print(1, n//2, n//2, n)
    else:
        ind = s.index('0')
        if ind < n // 2:
            print(ind+1, n, ind+2, n)
        else:
            print(1, ind+1, 1, ind)


for _ in range(int(input())):
    n = int(input())
    s = input()
    func()
