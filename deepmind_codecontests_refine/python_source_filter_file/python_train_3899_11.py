def main() :

    R = lambda : map(int, input().split())
    n, v = R()
    mlist = [0] * 3002
    for i in range(n) :
        a, b = R()
        mlist[a] += b
    mlist2 = mlist[:]
    ans = 0
    for i in range(1, 3001) :
        tmp = min(v, mlist[i])
        ans += tmp
        mlist[i + 1] += min(mlist[i] - tmp, mlist2[i])
    print(ans)

if __name__ == "__main__" :
    main()