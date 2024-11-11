def bubble_sort(l):
    for i in range(len(l) - 1):
        for j in range(len(l) - i - 1):
            if l[j] > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
    return l


def main_function():
    n = int(input())
    output_str = ""
    output_list = []
    for i in range(1, n):
        for j in str(i):
            output_list.append(j)
    return int(output_list[-1])


print(main_function())