n = int(input())
a = sorted(list(map(int,input().split())), reverse=True)
print(aum(a[::2]) - sum(a[1::2]))