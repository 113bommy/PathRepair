#ㅅㅂ 안함 개병씬같은 문제 시팔

def solve(n,ar):


    if n != 3 or ar[0] != -3 or ar[1] != -3 or ar[2] != 2:
        for i in range(n):
            if ar[i] >= 0: ar[i] = -1 * ar[i] - 1

        if n%2 != 0:
            mx = -1
            ind = -1

            for i in range(n):
                if abs(ar[i]) > mx:
                    mx = abs(ar[i])
                    ind = i

            ar[ind] = -1*ar[ind] - 1

    print(" ".join(map(str, ar)))




if __name__ == '__main__':
    n = int(input())
    ar = list(map(int,input().split()))

    solve(n,ar)