for i in range(int(input())):
    number = int(input())
    cout = 0
    while number > 0:
        if number % 2 == 1:
            cout += 1
        number //= 2

    print(2 ** cout, end="")
