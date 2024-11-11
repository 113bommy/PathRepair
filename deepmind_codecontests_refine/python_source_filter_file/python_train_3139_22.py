from math import ceil

def solve(hp, n, ds): 
    rd, ps = sum(ds), [0]
    for d in ds:
        ps.append(ps[-1] + d)
    mn, mc, rc = min(ps), 0, 0
    if mn >= 0 or (abs(mn) < hp and rd >= 0):
        return -1
    if rd < 0:
        rd, mn = abs(rd), abs(mn)
        rc = ceil((hp-mn) / rd)
        hp -= rc * rd
    for d in ds:
        if hp <= 0:
            break
        hp += d
        mc += 1
    return rc * n + mc

def main():
    hp, n = map(int, input().split())
    ds = list(map(int, input().split()))
    print(solve(hp, n, ds))

main()