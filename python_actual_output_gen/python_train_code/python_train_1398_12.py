n, *a = map(int, open(0).read().split())

ans = prev = 0
for i in a:
        tmp = divmod(i+prev, 2)
        ans += tmp[0]
        if i==0: prev=0
print(ans)