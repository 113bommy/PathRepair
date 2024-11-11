n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)
print(sun(a[::2])-sun(a[1::2]))