def main():
    n, n1, n2 = map(int, input().split())
    a = list(map(int, input().split()))
    
    # first remove the smallest wealth
    a.sort(reverse=True)
    a = a[:n1+n2]

    ans = 0
    if n2 > n1:
        # maximize S1
        ans = sum(a[:n1]) / n1 + sum(a[n1+1:]) / n2
    else:
        # maximize S2
        ans = sum(a[:n2]) / n2 + sum(a[n2:]) / n1

    print(ans)
    

if __name__ == '__main__':
    main()
