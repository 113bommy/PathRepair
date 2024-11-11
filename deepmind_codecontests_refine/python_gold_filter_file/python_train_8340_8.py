def read_input():
    n = int(input())
    line = input()
    line = line.strip().split()
    b = [int(num) for num in line]

    return n, b


def mishka_and_the_last_exam(n, b):
    l = [0] * n
    half = n // 2
    for i, sum_ in enumerate(b[::-1]):
        if i == 0:
            l[half - 1 - i] = sum_ // 2
            l[half + i] = sum_ - (sum_ // 2)
        elif i < half - 1:
            l[half -1 - i] = l[half - 1 - i + 1]
            l[half + i] = sum_ - l[half -1 - i]

            if l[half + i - 1] > l[half + i]:
                diff = l[half + i - 1] - l[half + i]
                l[half -1 - i] -= diff
                l[half + i] += diff
        else:
            l[0] = 0
            l[-1] = sum_
        
    return l


def print_results(result):
    result = [str(el) for el in result]
    print(" ".join(result))


if __name__ == "__main__":
    n, b = read_input()
    result = mishka_and_the_last_exam(n, b)
    print_results(result)
