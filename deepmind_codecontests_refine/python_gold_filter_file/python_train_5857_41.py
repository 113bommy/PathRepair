def main(n, r):
    sum0 = ((n - 1) * n)//2
    if r >= n: return sum0 + 1
    else: return ((r + 1) * r)//2

for _ in range(int(input())):
    n, r = [int(x) for x in input().split()]
    print(main(n, r))
