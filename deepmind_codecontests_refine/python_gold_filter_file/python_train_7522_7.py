def find_pos(a,i,m):
    while i < m:
        if a[i] > 0:
            return i
        else:
            i += 1
    return m

def main():
    n = int(input())
    for __ in range(n):
        m = int(input())
        a = list(map(int,input().split()))

        i = 0
        i = find_pos(a,i,m)
        neg = i+1
        while neg < m:
            if a[neg] < 0:
                if a[i] + a[neg] >= 0:
                    a[i] += a[neg]
                    a[neg] =  0
                    neg += 1
                else:
                    a[neg] += a[i]
                    a[i] = 0
                    i = find_pos(a,i,m)
                    if i > neg:
                        neg = i+1
            elif a[neg] >= 0 or neg <= i:
                neg += 1

        ans = 0
        for i in range(m):
            if a[i] > 0:
                ans += a[i]
        print(ans)

if __name__ == '__main__':
    main()
