###
 #    author:  Sooh
 #    created: 29.08.2021 23:40:19
###
import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    odd = []
    even = []
    for i in range(len(a)):
        if a[i] % 2 == 1 : 
            odd.append(i)
        else :
            even.append(i)
    if abs(len(odd) - len(even)) > 1:
        print(-1, flush = False)
        return
    ans1 = 0
    ans2 = 10**9
    cur = 0
    if len(odd) > len(even) : even, odd = odd, even
    for i in range(len(even)):
        ans1 += abs(even[i] - cur)
        cur += 2
    cur = 0
    if len(odd) == len(even):
        ans2 = 0
        for i in range(len(odd)):
            ans2 += abs(odd[i] - cur)
            cur += 2
    print(min(ans1, ans2), flush = False)

def main(): 
    t = int(input())
    while t:
        solve()
        t -= 1

if __name__ == '__main__':
    main()