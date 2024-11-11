t = int(input())
for i in range(t):
    n, s = int(input()), input()
    ix1, ix2 = s.find('1'), s[::-1].find('1')
    if (ix1 == ix2 == -1):
        print(n)
        continue
    print(max(n - ix1, ix2 - 0) * 2)
