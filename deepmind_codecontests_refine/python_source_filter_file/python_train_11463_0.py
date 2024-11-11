if __name__ == '__main__':
    # let's calculate n such that (a + b) * 2 = n * (n + 1)
    # n can be 10 ^ 5 at max
    # it is guaranteed that n cannot exceed this value
    # we now need to find combinations of a & b
    # which is as close to n as possible
    # trying all possible combinations is not an option
    # one greedy solution would be cram as much as possible in array and
    # when you get stuck shift some values to the other array
    a, b = map(int, input().split())

    n = None
    for i in range(10 ** 5):
        if i * (i + 1) <= (a + b) * 2:
            n = i
        else:
            break

    s1 = 0
    a1 = []
    a2 = []

    for i in range(1, n + 1):
        if s1 + i <= a:
            a1.append(i)
            s1 += i
        elif s1 < a:
            x = s1 + i - a
            a1.remove(x)
            a1.append(i)
            a2.append(x)
            s1 = a
        else:
            a2.append(i)

    print(s1)
    print(*a1)
    print(sum(a2))
    print(*a2)
