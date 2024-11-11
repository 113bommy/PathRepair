n = int(input())
a = list(map(int, input().split()))

cnt = [0] * 1001
for val in a:
    cnt[val] += 1


def solve():
    if n % 2 == 0:
        for i in range(1001):
            if cnt[i] % 4 != 0:
                print("NO")
                return
        pos = 0
        m = [[0]*n for _ in range(n)]
        for row in range(n//2):
            for row_or_col in range(n//2):
                while cnt[pos] == 0:
                    pos += 1
                m[row][row_or_col] = pos
                m[row][n-1-row_or_col] = pos
                m[n-1-row][row_or_col] = pos
                m[n-1-row][n-1-row_or_col] = pos
                cnt[pos] -= 4

        print('YES')
        for row in range(n):
            print(' '.join(map(str, m[row])))
    else:
        pos4 = 0
        pos2 = 0

        def next4(pos4):
            while pos4 < len(cnt) and (cnt[pos4] == 0 or cnt[pos4] < 4):
                pos4 += 1
            return pos4

        def next2(pos2):
            while pos2 < len(cnt) and (cnt[pos2] == 0 or cnt[pos2] < 2):
                pos2 += 1
            return pos2

        def next1():
            for pos in range(len(cnt)):
                if cnt[pos] > 0:
                    return pos
            return len(cnt)

        m = [[0]*n for _ in range(n)]

        # 4s first
        for row in range(n//2):
            for row_or_col in range(n//2):
                pos4 = next4(pos4)
                if pos4 >= len(cnt):
                    print('NO')
                    return
                cnt[pos4] -= 4
                m[row][row_or_col] = pos4
                m[row][n-1-row_or_col] = pos4
                m[n-1-row][row_or_col] = pos4
                m[n-1-row][n-1-row_or_col] = pos4

        # 2s next
        for row_or_col in range(n//2):
            if row_or_col != n//2:
                pos2 = next2(pos2)
                if pos2 >= len(cnt):
                    print('NO')
                    return
                cnt[pos2] -= 2
                m[n//2][row_or_col] = m[n//2][n-1-row_or_col] = pos2

                pos2 = next2(pos2)
                if pos2 >= len(cnt):
                    print('NO')
                    return
                cnt[pos2] -= 2
                m[row_or_col][n//2] = m[n-1-row_or_col][n//2] = pos2

        # 1s last
        pos1 = next1()
        if pos1 >= len(cnt):
            print('NO')
            return
        m[n//2][n//2] = pos1

        print('YES')
        for row in range(n):
            print(' '.join(map(str, m[row])))

solve()
