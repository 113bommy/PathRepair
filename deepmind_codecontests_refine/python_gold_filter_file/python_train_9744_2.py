#810A
n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = sum(a)/len(a)
count = 0
while ans < k-0.5:
    a.append(k)
    ans = sum(a)/len(a)
    count += 1
print(count)
