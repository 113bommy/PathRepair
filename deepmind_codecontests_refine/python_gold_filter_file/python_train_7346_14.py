import sys 


def main():
    n = int(sys.stdin.readline())

    if(n == 2):
        print(1)
        print(2)
        return

    s = 0
    nums_used = []

    for i in range(1, n + 1):
        if s + i > n:
            diff = n - s
            nums_used.append(nums_used.pop() + diff)
            break
        elif s + i == n:
            nums_used.append(i)
            break
        nums_used.append(i)
        s += i 

    print(len(nums_used))
    print(" ".join(map(str, nums_used)))

main()
