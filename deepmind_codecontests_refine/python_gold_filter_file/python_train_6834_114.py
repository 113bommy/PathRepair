def main():
    K = int(input())

    if K > 36:
        print(-1)
        return

    div_, mod_ = divmod(K, 2)
    n = '8' * div_
    if mod_:
        n = n + '9'
    print(n)

main()
