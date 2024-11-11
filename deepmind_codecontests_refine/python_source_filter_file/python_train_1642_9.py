#n, k = map(int, input().split(" "))
#LA = [int(x) for x in input().split()]

n, m, a, b = map(int, input().split(" "))
ans1 = (n % m) * a
ans2 = (m - (n % m)) * b
print(str(min(ans1,ans2)))
