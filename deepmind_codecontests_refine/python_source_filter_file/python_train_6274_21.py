# get the total number of testcase
tc = int(input())

# looping testcase one by one
for _ in range(tc):
    # get the length of array
    n = int(input())
    # get the array
    arr = list(map(int, input().split()))

    arr.reverse()
    print(arr)
