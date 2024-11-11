import sys

n, b, p = input().split(" ")
itr_cnt = 0
n = int(n)
b = int(b)
p = int(p)
n_ = n

if n == 1:
    print(b, p)
    sys.exit()

directly = 0
div = 2
while n >= 2:
    directly += n % 2
    # print("DIRECTLY: ", directly)
    n = int(n/2)
    # print("N: ", n)
    itr_cnt += n
    # print("itr_cnt: ", itr_cnt)



total_matches = itr_cnt + directly
# print("TOTAL_MATCHES: ", total_matches)

bottles = (total_matches * (2 * b)) + total_matches
towels = n_ * p
print(bottles, towels)