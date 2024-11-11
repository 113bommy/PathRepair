def solve(n,k):
    if(n%2==0):
        half = n//2
    else:
        half = n//2 + 1

    if(k<=half):
        return (2*k)-1
    else:
        return 2*(k-half)

if __name__ == "__main__":
    n,k = map(int,input().split())
    print(solve(n,k))