import sys

input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = 0
    q = set()
    for i in range(n):
        if a[i] == 1:
            if 1 not in q:
                q.add(1)
                ans += 1
            else:
                if 2 not in q:
                    q.add(2)
                    ans += 1
        else:
            if a[i] - 1 > 0 and a[i] - 1 not in q:
                q.add(a[i] - 1)
                ans += 1
            else:
                if a[i] not in q:
                    q.add(a[i])
                    ans += 1
                else:
                    if a[i] + 1 not in q:
                        q.add(a[i])
                        ans += 1
                    else:
                        continue
    return ans

if __name__=="__main__":
    print(main())
