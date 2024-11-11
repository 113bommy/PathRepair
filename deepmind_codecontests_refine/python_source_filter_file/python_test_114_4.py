for _ in range(int(input())):
    n = int(input())
    # n, k = map(int, input().split())
    arr= list(map(int, input().split()))
    # output_arr =[]

    arr.sort()
    for i in range(len(arr)//2):
        print(arr[i], arr[i+1])
    