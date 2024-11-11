import string

az = string.ascii_lowercase
az_dict = {x: i for (i, x) in enumerate(az)}


def solve(m, r):
    for i in range(m // 2):
        if (az_dict[r[i]] - az_dict[r[m - 1 - i]]) % 26 not in [0, 2, 24]:
            return False
    return True


t = int(input())
for case in range(t):
    n = int(input())
    s = input()
    if solve(n, s):
        print("YES")
    else:
        print("NO")
