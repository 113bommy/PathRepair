from math import log
def main(a, m):
    for k in range(2 + int(log(m))):
        if (a * (2 ** k)) % m == 0:
            return True
    return False

print("Yes" if main(*list(map(int, input().split(' ')))) else "No")
