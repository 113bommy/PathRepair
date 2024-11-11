n = int(input())
x = list(map(int, input().split( )))
x2 = [x[i] for i in range(n)]

x2.sort()

ans1 = x2[n//2-1]
ans2 = x2[n//2]

for i in range(n):
    if x[i]<=ans1:
        print(ans2)
    elif x[i]==ans2:
        print(ans1)
    else:
        print(ans2)
