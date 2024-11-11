n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = n - k
even = sum([i % 2 == 0 for i in a])
odd = sum([i % 2 == 1 for i in a])
f1 = cnt % 2 == 0 and k % 2 == 1 and even <= cnt // 2
f2 = cnt % 2 == 1 and not (k % 2 == 0 and even <= cnt // 2 or odd <= cnt // 2)
f3 = cnt == 0 and odd % 2 == 1
ans = 'Stannis' if f1 or f2 or f3 else 'Daenerys'
print(ans)