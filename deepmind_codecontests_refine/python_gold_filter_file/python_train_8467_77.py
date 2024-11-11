# 199A
z = int(input())
all_fib = [0, 1, 1]
while all_fib[-1] < z:
    all_fib.append(all_fib[-2] + all_fib[-1])


def check(num):
    result = [0, 0, 0]
    for i in all_fib:
        for j in all_fib:
            for k in all_fib:
                if i + j + k == z:
                    return (i, j, k)
    return result


x = check(z)
if x == [0, 0, 0]:
    print("I'm too stupid to solve this problem")
else:
    print(x[0], x[1], x[2])