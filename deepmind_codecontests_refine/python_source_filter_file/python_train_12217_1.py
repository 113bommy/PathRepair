


l, r = map(int, input().split())

result = 0

for digit in range(1, 10):
    d_str = str(digit)
    for length in range(3, 18):
        if int(d_str + (length - 2) * '0' + d_str) <= r and \
                int(d_str + (length - 2) * '9' + d_str) >= l:
            a, b, c = 0, int((length - 2) * '9'), 0
            while a < b:
                c = (a + b) // 2
                if int(d_str + '0' * (length - 2 - len(str(c))) + str(c) + d_str) < l:
                    a = c + 1
                else:
                    b = c
            l_end = a
            a, b, c = 0, int((length - 2) * '9'), 0
            while a < b:
                c = (a + b + 1) // 2
                if int(d_str + '0' * (length - 2 - len(str(c))) + str(c) + d_str) > r:
                    b = c - 1
                else:
                    a = c
            r_end = a
            #print(str(l_end) + " " + str(r_end))
            #print("     " + str(d_str + '0' * (length - 2 - len(str(l_end))) + str(l_end) + d_str))
            #print("     " + str(d_str + '0' * (length - 2 - len(str(r_end))) + str(r_end) + d_str))
            result += r_end - l_end + 1

for digit in range(1, 10):
    length = 1
    if l <= digit and digit <= r:
        result += 1
    length = 2
    if int(str(digit) + str(digit)) >= l and int(str(digit) + str(digit)) <= r:
        result += 1

print(result)
