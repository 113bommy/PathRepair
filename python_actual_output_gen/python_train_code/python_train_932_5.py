def Main():
    n , a , b = map(int ,input().split())
    s = input()

    if s[a - 1] == s[b - 1]:
        print(0)
        return 0
    else:
        start = s[a - 1]
        finish = s[b - 1]
        cnt = 0
        for i in range(len(s)):
            if s[i] == finish:
                break
            else:
                cnt += 1

        print(cnt)

if __name__ == '__main__':
    Main()