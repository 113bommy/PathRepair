def main():
    n,k = map(int,input().split())
    e = [[0]*(2*k) for i in range(2*k)]
    mod = 2*k
    for i in range(n):
        x,y,c = input().split()
        if c == "W":
            x = int(x)%mod
            y = (int(y)+k)%mod
        else:
            x = int(x)%mod
            y = int(y)%mod
        e[x][y] += 1

    for i in range(mod):
        for j in range(mod):
            if i != 0 and j != 0:
                e[i][j] -= e[i-1][j-1]
            if i != 0:
                e[i][j] += e[i-1][j]
            if j != 0:
                e[i][j] +=e[i][j-1]

    ans = 0
    for i in range(k+1):
        for j in range(k+1):
            count = e[-1][-1]+2*e[i+k-1][j+k-1]-e[-1][j+k-1]-e[i+k-1][-1]
            if i != 0 and j != 0:
                count += 2*e[i-1][j-1]
            if i != 0:
                count += e[i-1][-1]-2*e[i-1][j+k-1]
            if j != 0:
                count += e[-1][j-1]-2*e[i+k-1][j-1]
            ans = max(ans,count)
    print(ans)
if __name__ == "__main__":
    main()
