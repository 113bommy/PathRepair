def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = input()

    re = int(1e9)
    le = -re
    x = True
    for i in range(n):
        if b[i] == ('1' if x else '0'):
            for j in a[i - 4:i + 1]:
                if x:
                    if le <= j:
                        le = j + 1
                else:
                    if re >= j:
                        re = j - 1
            x = not x
    print(le, re)


if __name__ == "__main__":
    main()
