def solution():
    from sys import stdout, stdin
    _input, _print = stdin.readline, stdout.write
    _int, _range, _min, _max = int, range, min, max
    n = int(input())
    arr = [1 if i == '(' else -1 for i in input()]
    if sum(arr) > 0:
        print("No")
    else:
        s = [0]*n
        for i in range(n):
            if i == 0:
                s[i] = arr[i]
            else:
                s[i] = arr[i] + s[i-1]
                if s[i] == -2:
                    print("No")
                    break
        else:
            print("Yes")
solution()
