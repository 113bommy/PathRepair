num = int(input())
l = [int(x) for x in input().split(" ")]
s, t = list(map(int, input().split()))
sum_1 = sum(l[s-1: t-1])
print(min(sum_1, sum(l)-sum_1))
