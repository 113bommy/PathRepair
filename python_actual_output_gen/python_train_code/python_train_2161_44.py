z = int(input())
for t in range(z):
    n = int(input())
    arr = list(map(int,input().split()[:n]))
    print(arr[n-1::-1])