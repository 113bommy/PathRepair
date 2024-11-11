def main():
    from collections import defaultdict
    (n, m) = map(int, input().split(' '))
    l = [0] * 101
    end = False
    for i in range(n):
        (a, b) = map(int, input().split(' '))
        if b == m:
            end = True
        for i in range(a, b):
            l[i] += 1
    for i in range(0, m):
        if l[i] == 0:
            return False
    return end
print("YES" if main() else "NO")
