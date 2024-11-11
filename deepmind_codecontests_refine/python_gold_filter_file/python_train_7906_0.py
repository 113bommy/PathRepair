N = int(input())
n = 1
ans = 1

while True:
    n *= 3
    if n>=N:
        print(ans)
        break
    ans+=1


