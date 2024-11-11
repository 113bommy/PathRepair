import sys
f = sys.stdin
#f = open("input.txt", "r")
def solve():
    global f
    a = f.read().strip().split("\n")
    for l in range(7):
        count = 0
        for i in range(7):
            if a[l][i] == a[l][i+1]:
                count += 1
                if count >= 2:
                    print("NO")
                    return
    for l in range(1, 7):
        for i in range(1, 7):
            if a[l][i] == a[l+1][i] == a[l][i+1] == a[l+1][i+1]:
                print("NO")
                return
    else:
        print("YES")
        return
solve()