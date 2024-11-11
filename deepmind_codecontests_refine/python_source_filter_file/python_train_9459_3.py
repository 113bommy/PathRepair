def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    b = sorted(a)
    c = b[::2]
    d = a[::2]
    set_c = set(c)
    set_d = set(d)
    print(len(set_c & set_d))

main()