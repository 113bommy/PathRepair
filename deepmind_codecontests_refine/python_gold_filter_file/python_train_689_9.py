

def solve(n, d, arr):

    tempLen = 0
    for i in range(n):
        for j in range(i, n):
            tempdiff = abs(arr[j] - arr[i])
            templen = (j - i) + 1
            if tempdiff <= d and templen >= tempLen:
                tempLen = templen

    print(n - tempLen)


# Main
def run():
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))

    if len(arr) == 1:
        print(0)
    else:
        arr.sort()
        solve(n, d, arr)

# end main


# Program Start
if __name__ == "__main__":
    run()