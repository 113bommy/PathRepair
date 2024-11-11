


in_arr = input().split()
b, k = int(in_arr[0]), int(in_arr[1])

in_arr = input().split()
a_arr = [int(x) for x in in_arr]


n = 0
if b % 2 == 0 and a_arr[-1] % 2 == 0:
    print("even")
    exit(0)

n = a_arr[-1]
n = n % 2
for i in range(k-1):
    n += a_arr[k-i-1]*b
    n = n % 2

if n % 2 == 0:
    print("even")
else:
    print("odd")
