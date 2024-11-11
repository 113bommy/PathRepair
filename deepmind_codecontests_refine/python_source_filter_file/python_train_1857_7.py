n = int(input())
c = sorted(list(map(int, input().split())))
print(sum(c[0::2]) - sum(c[1::2]))