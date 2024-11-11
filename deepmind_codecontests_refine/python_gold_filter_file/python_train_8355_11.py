def divisors(a, b):
    result = []
    x = b - a
    for i in range(1, x + 1):
        if x % i == 0:
            result.append(i)
    return result


def solution():
    x = int(input())
    for _ in range(x):
        n, x, y = input().split()
        my_divisors = divisors(int(x), int(y))
        gap = int(y) - int(x)
        current_max = int(y) - int(x)
        if int(y) - int(x) - 1 == int(n) - 2:
            current_max = 1
        else:
            for i in range(len(my_divisors)):
                if (my_divisors[i] * int(n) - 2) >= gap >= gap - my_divisors[i]:
                    current_max = my_divisors[i]
                    break
        count = int(n) - 1
        current = int(x)
        print(str(current), end="")
        current += current_max
        while current < int(y) and count > 1:
            print(" " + str(current), end="")
            current += current_max
            count -= 1
        print(" " + str(int(y)), end="")
        count -= 1
        current = int(x) - current_max
        while current >= 1 and count > 0 :
            print(" " + str(current), end="")
            current -= current_max
            count -= 1
        current = int(y) + current_max
        while count > 0 :
            print(" " + str(current), end="")
            current += current_max
            count -= 1
        print()
solution()