
if __name__ == "__main__":
    n = int(input())
    a = list(map(int , input().split()))

    a.sort()
    total_time = a[0]
    ans = 1

    for i in range(1,n):
        if a[i] >= total_time:
            ans +=1
        total_time += a[i]
    print(ans)
