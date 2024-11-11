from sys import stdin, gettrace

if gettrace():
    def inputi():
        return input()
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    n,m = map(int, input().split())
    ll = []
    for _ in range(n):
        ll.append(input())
    if m%2 == 1:
        print("YES")
        print("1 2 "*((m+1)//2))
        return
    if n == 2 and ll[0][1] != ll[1][0]:
        print("NO")
        return
    if ll[0][1] == ll[1][0]:
        print("YES")
        print("1 2 "*(m//2) + "1")
        return
    if ll[1][2] == ll[2][1]:
        print("YES")
        print("2 3 "*(m//2) + "2")
        return
    if ll[2][0] == ll[0][2]:
        print("YES")
        print("3 1 "*(m//2) + "3")
        return
    if ll[0][1] == ll[1][2]:
        print("YES")
        if m%4 == 0:
            print("2 1 "*(m//4) + "2 3 "*(m//4) + "2")
        else:
            print("1 " + "2 1 "*(m//4) + "2 3 "*(m//4) + "2 3")
        return
    if ll[1][2] == ll[2][0]:
        print("YES")
        if m%4 == 0:
            print("3 2 "*(m//4) + "3 1 "*(m//4) + "3")
        else:
            print("2 " + "3 2 "*(m//4) + "3 1 "*(m//4) + "3 1")
        return
    if ll[2][0] == ll[0][1]:
        print("YES")
        if m%4 == 0:
            print("1 3 "*(m//4) + "1 2 "*(m//4) + "1")
        else:
            print("3 " + "1 3 "*(m//4) + "1 2 "*(m//4) + "1 2")
        return



def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
