from math import factorial
mod = 10 ** 9 + 7
n = int(input())
inp = list(input())
if inp[0] == 'W' or inp[-1] == 'W':
    print(0)
    exit(0)
arr = ['L']
swap_dict = {'L': 'R', 'R': 'L'}
for i in range(1, 2 * n):
    arr.append(arr[i - 1] if inp[i] != inp[i - 1] else swap_dict[arr[i - 1]])
if arr.count('L') != arr.count('R'):
    print(0)
    exit(0)
cnt_tmp = 0
cnt_swap = 1
for a in arr:
    if a == 'L':
        cnt_tmp += 1
    else:
        cnt_swap = (cnt_swap * cnt_tmp) % mod
        cnt_tmp -= 1
print(cnt_swap * factorial(n))