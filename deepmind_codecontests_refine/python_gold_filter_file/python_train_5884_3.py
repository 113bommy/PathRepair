def main():
    left,r = map(int,input().split())
    ans = 0
    for l in range(1,61):
        for i in range(l):
            s = ''
            for j in range(l):
                if i == j:
                    s += '0'
                else:
                    s += '1'

            x = int(s,2)
            if bin(x)[2:].count('0') == 1 and left <= x <= r:
                ans += 1

    print(ans)


main()
