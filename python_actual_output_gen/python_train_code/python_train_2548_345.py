n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)
print(sum(a[n:n*2]))