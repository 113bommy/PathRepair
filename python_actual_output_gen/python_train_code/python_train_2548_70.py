n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)

print(a[1:n*2:2])