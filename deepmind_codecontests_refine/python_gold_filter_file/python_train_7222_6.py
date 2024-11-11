import io
import os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def main():
    g = [[] for _ in range(4)]
    for i in range(4):
        g[i] = input()

    ok = False
    for i in range(3):
        for j in range(3):
            x = [g[i][j], g[i][j+1], g[i+1][j], g[i+1][j+1]]
            if x.count('#') > 2 or x.count('.') > 2:
                ok = True
                break

        if ok:
            break

    print('YES' if ok else 'NO')


if __name__ == '__main__':
    main()
