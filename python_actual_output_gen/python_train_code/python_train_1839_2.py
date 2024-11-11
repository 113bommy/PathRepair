n = int(input())

l = list(map(int,input().split()))

m = min(l)

ans = 0

for i in l:
    ans += i == m


if ans * 2 >= n:
    print('Alice')
else:
    print('Bob')