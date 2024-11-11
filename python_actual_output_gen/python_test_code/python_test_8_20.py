tc = int(input())
for i in range(tc):
    s, a, b, c = [int(x) for x in input().split()]
    ans = (s // c) + (s // a) * b
    print(ans)