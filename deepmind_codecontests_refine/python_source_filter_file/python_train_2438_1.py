# link: https://codeforces.com/problemset/problem/370/B

import sys

def solve(info, n):
    for i in range(n):
        flag = False
        for j in range(n):
            if i==j:
                continue
            else:
                if info[i].issuperset(info[j]):
                    flag = True
                    break
        if not flag:
            print("Yes")
        else:
            print("No")            

if __name__ == "__main__":
    i = sys.stdin.readline
    n = int(i())
    info = []
    for _ in range(n):
        l = list(map(int, i().split()))
        info.append(set(l[1:]))
    solve(info, n)    