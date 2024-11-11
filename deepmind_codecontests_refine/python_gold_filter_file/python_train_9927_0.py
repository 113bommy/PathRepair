

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    copy = arr[:]
    copy.sort()

    missed = 0
    for i in range(n):
        if arr[i] != copy[i]:
            missed += 1

    if missed == 2:
        print('YES')
    elif missed == 0:
        print('YES')
    else:
        print('NO')




main()