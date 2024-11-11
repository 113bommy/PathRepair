def main():
    n, m, a, b = input().split(' ')

    n = int(n)
    m = int(m)
    a = int(a)
    b = int(b)

    mod = n % m
    div = n // m
    if mod != 0:
        if n > m:
            plus = ((div+1)*m-n)*a
            minus = (n-div*m)*b
            ans = min(plus, minus)
        elif n < m:
            plus = (div*m-n)*a
            minus = n*b
            ans = min(plus, minus)
    else:
        ans = 0

    print(ans)

if __name__ == '__main__':
    main()