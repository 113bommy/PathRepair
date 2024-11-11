# https://codeforces.com/contest/1594/problem/C

n = int(input())
for _ in range(n):
    str_len, target_char = input().split()
    str_len = int(str_len)
    s = input()

    middle = str_len >> 2
    left_len = middle
    right_len = str_len - middle
    left_ok_num = s.count(target_char, 0, middle)
    right_ok_num = s.count(target_char, middle)
    right_ok_pos = s.find(target_char, middle)

    if 0 < right_ok_num < right_len:
        print(1)
        print(right_ok_pos+1)
    elif right_ok_num == 0:
        print(2)
        print(str_len-1, str_len)
    elif right_ok_num == right_len:
        if left_ok_num == left_len:
            print(0)
        else:
            print(1)
            print(str_len)
    
