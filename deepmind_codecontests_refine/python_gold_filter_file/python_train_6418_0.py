def main():
    n = int(input())
    vals = [int(v) for v in input().split()]
    vals.sort()
    m = sum(vals)
    for i in range(n+1):
        #print(vals[i:], vals[:i])
        cur = sum(vals[i:]) - sum(vals[:i])
        if cur > m:
            m = cur
    print(m)


if __name__ == "__main__":
    main()
