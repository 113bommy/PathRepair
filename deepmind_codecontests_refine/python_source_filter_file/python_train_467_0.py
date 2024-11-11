def main():
    n = int(input())
    a = list(map(int, input().split()))
    max_element = max(a) + 1
    print(max_element)
    diff_freq = [0 for i in range(max_element)]
    for i in range(n):
        for j in range(i):
            diff_freq[abs(a[i] - a[j])] += 1

    largest = [0 for i in range(max_element)]
    for i in range(max_element - 2, 0, -1):
        largest[i] = largest[i + 1] + diff_freq[i + 1]

    good_ones = 0

   # print('diff_freq', diff_freq)
#    print('largest', largest)

    for i in range(max_element):
        for j in range(max_element):
            if i + j < max_element:
                good_ones += diff_freq[i] * diff_freq[j] * largest[i + j]

#    print(good_ones)
    ans = good_ones / (((n*(n - 1)) / 2) ** 3)
    print(ans)
main()