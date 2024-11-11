def main():
    n = int(input())
    sx,sy,sxy,ans = {},{},{},0
    for i in range(n):
        (a,b) = map(int,input().split())
        ans += sx.get(a,0) + sy.get(b,0) - sxy.get((a,b),0)
        sx[a] = sx.get(a,0) + 1
        sy[b] = sx.get(b, 0) + 1
        sxy[(a,b)] = sxy.get((a,b), 0) + 1
    print(ans)

if __name__ == "__main__":
    main()