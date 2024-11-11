

def solve():
    n, k = (int(x) for x in input().split())
    arr = [int(x) for x in input().split()]

    d =[0 for _ in range(n-1)]

    for i in range(n-1):
        d[i] = arr[i+1] - arr[i]

    # print(d)
    
    d.sort()

    # print(d[:-k+1])
    ans = sum(d[:n-k])

    print(ans)
        

if __name__ == "__main__":
    solve()
