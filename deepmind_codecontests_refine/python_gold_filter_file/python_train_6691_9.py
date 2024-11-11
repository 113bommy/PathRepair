import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))

test_cases = inp()
max_poss = 3123456

def solve():
    n = inp()
    arr = inlt()

    fin_steps = []

    total_sum = sum(arr)

    if total_sum % n != 0:
        print('-1\n')
        return

    avg = int(total_sum / n)

    ind = 1

    while ind < n:
        if arr[ind] % (ind + 1):
            num = ind + 1 - arr[ind] % (ind + 1)
            arr[ind] += num
            arr[0] -= num
            fin_steps.append((1, ind + 1, num))

        num = int(arr[ind] / (ind + 1))
        arr[ind] -= num * (ind + 1)
        arr[0] += num * (ind + 1)
        fin_steps.append((ind + 1, 1, num))

        ind += 1

    ind = 1
    while ind < n:
        if arr[ind] < avg:
            num = avg - arr[ind]
            arr[ind] += num
            arr[0] -= num
            fin_steps.append((1, ind + 1, num))

        ind += 1

    print("{}\n".format(len(fin_steps)))

    for step in fin_steps:
        print("{} {} {}\n".format(step[0], step[1], step[2]))

for test in range(test_cases):
    solve()