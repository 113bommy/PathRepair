n = int(input())
a = sorted(list(map(int,input().split())))
print(sum(a[1::2])-sum(a[0::2]))