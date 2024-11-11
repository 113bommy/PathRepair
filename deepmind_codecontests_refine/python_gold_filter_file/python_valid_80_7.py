t = int(input())

for w in range(t):
    n = int(input())
    code = input()

    N = []
    for i in range(n):
        if code[i] == '0':
            N.append(i + 1)
    
    if N == []:
        print(1, n - 1, 2, n)
    elif N[-1] > n // 2:
        print(1, N[-1], 1, N[-1] - 1)
    else:
        print(N[0], n, N[0] + 1, n)
