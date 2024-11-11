def main():
    n, k = map(int, input().split(" "))
    if k == 1:
        print(n)
    else:
        s = bin(n)
        s1 = ''
        for i in range(s.__len__() - 2):
            s1 = s1 + '1'
        print(int(s1, 2))

main()