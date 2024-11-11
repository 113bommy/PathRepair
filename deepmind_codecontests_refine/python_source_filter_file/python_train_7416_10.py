heigth = [(i*(3*i+1))/2 for i in range(1,25820)]
for _ in range(int(input())):
    n=int(input())
    ans = 0
    for i in heigth[::-1]:
        if(i<=n):
            n-=i
            ans += 1
    print(ans)