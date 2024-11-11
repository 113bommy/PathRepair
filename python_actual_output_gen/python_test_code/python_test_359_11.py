n = int(input())
a,b,c = input(),input(),input()

ans = 0
for i in range(n):
	cnt = len(set(a[i],b[i],c[i]))-1
	ans += cnt

print(ans)
