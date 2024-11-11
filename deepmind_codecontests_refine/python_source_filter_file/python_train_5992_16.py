if __name__ == '__main__':
    n = int(input())
    arr = list(map(int,input().split()))
    av = (sum(arr)//n) *2
    for i in range(n):
        if arr[i] != 0:
            for j in range(n):
                if arr[i] + arr[j] == av and i != j:
                    print(i+1,j+1)
                    arr[i] = 0
                    arr[j] = 0