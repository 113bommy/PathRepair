import sys
input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1 and a[0] == 0:
        return -1
    if n == 1 and a[0] != 0:
        return 1
    if a[0] == 0 and a[1] > 1:
        return 2
    if a[0] != 0 or a[1] > 1:
        return 1
    used = set()
    used.add(a[0])
    used.add(a[1])
    ans = 0
    mx = max(a[0], a[1])
    for i in range(2, n):
        if a[i] not in used and abs(a[i] - mx) > 1:
            ans = i+1
            break
        else:
            used.add(a[i])
            mx = max(mx, a[i])
    if ans == 0:
        return -1
    return ans

if __name__=="__main__":
    print(main())