N = int(input())
a = list(map(int, input().split()))
a.sort()
print(sum(a[-N*2:-N]))


