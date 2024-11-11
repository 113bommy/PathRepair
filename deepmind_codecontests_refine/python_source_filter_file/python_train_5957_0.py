from heapq import heappush, heappop
from collections import Counter

def main():
    n = int(input())
    aa = [int(a)-1 for a in input().split()]
    saa = set(aa)
    caa = Counter(aa)
    ready = []
    for i in range(n):
        if i not in saa:
            heappush(ready, (i,i))
    print(aa[0] + 1)
    for a in aa[::-1]:
        imp, c = heappop(ready)
        print(a, c)
        caa[a] -=1
        if caa[a] == 0:
            heappush(ready, (max(a, imp), a))

if __name__ == "__main__":
    main()