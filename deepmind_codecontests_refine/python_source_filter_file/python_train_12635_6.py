def main():
    n,m = [int(v) for v in input().split()]
    data = [int(v) for v in input().split()]
    neg = [-1*v for v in data if v<0]
    pos = [v for v in data if v > 0]
    pos.sort()
    neg.sort(reverse=True)

    if m>len(neg):
        res = (sum(pos)+sum(neg))
        if len([v for v in data if v==0])!=0:
            print(res)
        else:
            if (m-len(neg))%2==0:
                print(res)
            else:
                d = min([abs(v) for v in data])
                print(res-d)
    else:
        print(sum(pos) + sum(neg[0:m])-sum(neg[m:]))


if __name__ == "__main__":
    main()
