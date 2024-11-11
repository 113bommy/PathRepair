f = ['0','0','2','3','22','5','53','7','7222','7332']
n = int(input())
a = input().strip()
ans=""
for i in range(n):
    if a[i] != '0' and a[i] != '1':
        ans += f[int(a[i])]

print(''.join(sorted(ans,reverse = True)))