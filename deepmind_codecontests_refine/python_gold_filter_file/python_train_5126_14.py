from collections import Counter


def main():
    test = int(input())

    for t in range(test):
        l = [int(i) for i in input().split(" ")]
        n = l[0]
        x = l[1]
        l = [int(i) for i in input().split(" ")]
        l = list(set(l))

        l.sort()
        num = 1
        i = 0
        ans = 0

        while i < len(l):
            if l[i] != num:
                if x > 0:
                    if l[i]-num <= x:
                        ans = l[i]
                        x -= (l[i] - num)
                        num = l[i]+1
                    else:
                        ans = num+x-1
                        x = 0
                        break
                else:
                    break
            else:
                num += 1
                ans += 1
            i += 1

        print(ans+x)

main()
