t = int(input())


def make_string(length, letter_count):
    dif = length - letter_count
    result = "a" * dif
    for i in range(letter_count):
        result += chr(ord('a') + i)
    return result

for i in range(t):
    numbers = list(map(int, input().split()))
    n = numbers[0]
    a = numbers[1]
    b = numbers[2]

    ans = make_string(a, b)
    while len(ans) < n:
        ans += make_string(a, b)

    print(ans)
