a = int(input())
c = list(map(int,input().split()))
su = sum(c)
diff = 1e10
cc = 0
for x in range(a-1):
    cc += c[x]
    diff = min(diff,abs(su-2*cc))
print(diff)
