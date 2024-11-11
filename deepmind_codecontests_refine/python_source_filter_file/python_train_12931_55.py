def main():
    n, m = input().split()
    s1 = input().split()
    s2 = input().split()
    q = int(input())
    for i in range(q):
        a = int(input())
        print(s1[a % int(n)] + s2[a % int(m)])


if __name__ == '__main__':
    main()
