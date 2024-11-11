from sys import stdin

input = stdin.readline


def main():
    test = int(input())

    for _ in range(test):
        n = int(input())
        l = [int(i) for i in input().split(" ")]
        # a, b = [int(i) for i in input().split(" ")]
        # a,b,c,d = [int(i) for i in input().split(" ")]
        #
        # l = []
        # l = [int(i) for i in input().split(" ")]
        #
        flag = False

        for i in range(1, 1025):
            s = set(l)
            flag = False
            for k in l:
                if k ^ i in s:
                    s.remove(k ^ i)
                else:
                    flag = True
                    break

            if not flag:
                print(i)
                break

        if flag:
            print(-1)


        #     # print(i ^ , end=' ')
        # print()


main()
