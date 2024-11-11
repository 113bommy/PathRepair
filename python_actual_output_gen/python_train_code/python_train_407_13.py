#1131C
n = int(input())
a = list(map(int, input().split()))
print(*(a[::2] + a[1::2][::-1]))
