N = int(input())
a = sorted(list(map(int,input().split())),reverse=True)
print(sum(a)-sum(a[::2]))