from collections import Counter

def solve():
    lines = []
    nr = int(input())
    for i in range(nr):
        n, *r = [int(x) for x in input().split(" ")]
        lines += r
    c = Counter(lines)
    ans = [x for x in c if c[x] == nr]
    print("".join([str(x) for x in ans]))

if __name__ == "__main__":
    #for i in range(int(input())):
    solve()