for _ in range(int(input())):
    n = int(input())
    for n_i in range(1, n + 1):
        ans = ['('] * n_i + [')'] * n_i + ['('] * (n - n_i) + [')'] * (n - n_i)

        print(''.join(ans))





