N = int(input())
a = sorted(list(map(int, input().split())), reverse=True)
print(sum(a[1:N*2:2]))