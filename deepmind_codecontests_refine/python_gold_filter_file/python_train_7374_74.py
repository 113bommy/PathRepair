n = int(input())
su = 0
for i in range(n):
    l, r = map(int, input().split())
    su += r-l+1
print(su)