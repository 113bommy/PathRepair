


if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        twone = []
        one = []
        two = []
        n = len(s)

        for i in range(n - 5 + 1):
            if s[i : i + 5] == "twone":
                twone.append(i)
        for i in range(n - 3 + 1):
            if s[i : i + 3] == "one":
                one.append(i)
        for i in range(n - 3 + 1):
            if s[i : i + 3] == "two":
                two.append(i)
        
        print(len(one) + len(two) - len(twone))
        twoneset = set(twone)

        for num in one:
            if num - 2 not in twoneset:
                print(num + 2, end = ' ')
        for num in two:
            if num not in twoneset:
                print(num + 2, end = ' ')
        for num in twone:
            print(num + 3, end = ' ')
        # print(one)
        print()
        