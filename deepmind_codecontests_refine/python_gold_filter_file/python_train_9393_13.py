# Problem URL: https://codeforces.com/contest/1326/problem/A
t = int(input())

for i in range(t):
    n = int(input())
    if n == 1:
        print(-1)
    else:
        print(2,end="")
        for i in range(n-1):
            if i!=n-2:
                print(3,end="")
            else:
                print(3)
    