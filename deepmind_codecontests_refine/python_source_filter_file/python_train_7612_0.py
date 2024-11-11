# link: https://codeforces.com/problemset/problem/1105/C

for _ in range(1):
    n, left, right = map(int, input().split())
    list_ = [((right - remainder) // 3) - ((left - remainder - 1) // 3) for remainder in range(3)]
    a,b,c = list_[0], list_[1], list_[2]
    for _ in range(n):
        temp_a = (a * list_[0] + b * list_[2] + c * list_[1]) % 1000000007
        temp_b = (a * list_[1] + b * list_[0] + c * list_[2]) % 1000000007
        temp_c = (a * list_[2] + b * list_[1] + c * list_[0]) % 1000000007
        a,b,c = temp_a, temp_b, temp_c
    print(a)    