from collections import defaultdict
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    alst.sort(reverse = True)
    max_a = alst[0]
    dd = defaultdict(int)
    for a in alst:
        dd[a] += 1
    i = 1
    while i < max_a:
        i *= 2
    ans = 0
    for a in alst:
        if dd[a] <= 0:
            continue
        while i > a * 2:
            i /= 2
        dd[a] -= 1
        num = i - a
        if dd[num]:
            ans += 1
            dd[num] -= 1
    print(ans)
    
main()