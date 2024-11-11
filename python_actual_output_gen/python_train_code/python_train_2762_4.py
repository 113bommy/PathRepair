t = int(input())
for _ in range(t):
    n = int(input())
    ans=""
    p = n//4 + 1
    ans+=(n-p)*"9"+p*"8"
    print(ans)