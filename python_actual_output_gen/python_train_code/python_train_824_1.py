n = int(input())
a = [int(i) for i in input().split()]
for i in range(n):
    print(min(abs(a[i]-a[(i+1)%n]), abs(a[i]-a[i-1])), max(abs(a[i]-a[0]), abs(a[i]-a[1])))