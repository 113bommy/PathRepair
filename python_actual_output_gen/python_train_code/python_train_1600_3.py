def count_even(a):
    ans = 0
    for i in a:
        if i % 2 == 0:
            ans += 1

    return ans


t = int(input())
for i in range(t):
    n = int(input())
    arr1 = list(map(int, input().split()))
    m = int(input())
    arr2 = list(map(int, input().split()))
    even_arr1 = count_even(arr1)
    odd_arr1 = even_arr1 - n
    even_arr2 = count_even(arr2)
    odd_arr2 = even_arr1-m
    print(even_arr1*even_arr2 + odd_arr1*odd_arr2)
