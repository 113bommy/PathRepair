n = int(input())
a = list(map(int,input().split()))
for i in a:
    if i%2!=a[0]%2:
        print(*sorted(a))
        exit()
else:
    print(a)