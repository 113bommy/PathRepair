def crossRange(r1, r2):
    low = max(r1[0], r2[0])
    high = min(r1[1], r2[1])
    return low <= high

if __name__ == "__main__":
    l, r, x, y, k = map(int, input().split())
    r1 = ((l+k-1)//k, r//k)
    print("YES" if crossRange(r1, (x, y)) else "NO")
