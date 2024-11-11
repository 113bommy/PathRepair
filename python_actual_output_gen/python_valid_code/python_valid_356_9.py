import sys

TEST = 0

if TEST == 1:
    input_file = open("inputA.txt", "r")
    input_from_file = input_file.readlines()

def read_int():
    if TEST:
        return int(input_from_file.pop(0))
    else:
        return int(sys.stdin.readline())

def read_ints():
    if TEST:
        return list(map(int, input_from_file.pop(0).rstrip().split()))
    else:
        return list(map(int, sys.stdin.readline().split()))


t = read_int()

def nextDiff(a):
    dig = [int(x) for x in str(a)]
    return min(dig)*max(dig)

for j in range(t):
    a, K = read_ints()
    j = 0
    while j < K:
        diff = nextDiff(a)
        if diff == 0:
            break
        a += diff
        j += 1
    ans = a

    print(ans)


