def solve(n, binaryString):
    for i in range(n):
        if binaryString[i] == '0':
            if i < n // 2:
                print(i + 1, n, i + 2, n)
            else:
                print(1, i + 1, 1, i)
            return
    print(1, n // 2 + 1, 1, n // 2)
            
t = int(input())
for _ in range(t):
    n = int(input())
    binaryString = input()
    solve(n, binaryString)