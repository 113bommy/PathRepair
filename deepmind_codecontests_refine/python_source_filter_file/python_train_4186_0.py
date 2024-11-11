if __name__ == '__main__':
    t = int(input())
    while t:
        n = int(input())
        s = input()

        max_len = 0
        for i, e in enumerate(s):
            if e == '1':
                max_len = max(max_len, n - i, i)
        print(max(2*max_len, n))
        t -= 1
