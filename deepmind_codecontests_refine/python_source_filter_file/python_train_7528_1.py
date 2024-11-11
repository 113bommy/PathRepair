if __name__ == '__main__':

    for t in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))

        cnt = 0

        for w in range(3, 5):
            for i in range(len(a) - w + 1):

                if w == 3:
                    if (a[i + 1] - a[i]) * (a[i + 2] - a[i + 1]) < 0:
                        cnt += 1
                else:
                    if (a[i + 1] - a[i]) * (a[i + 2] - a[i + 1]) < 0 \
                    and (a[i + 1] - a[i]) * (a[i + 3] - a[i + 1]) < 0\
                    and (a[i + 2] - a[i + 1]) * (a[i + 3] - a[i + 2]) < 0\
                    and (a[i + 2] - a[i]) * (a[i + 3] - a[i + 2]):
                        cnt += 1

        print(cnt + 2 * len(a) - 1)


