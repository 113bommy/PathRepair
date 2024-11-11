for _ in range(int(input())):
    n=int(input())
    p=list(map(int, input().split()))
    for i in range(n):
        if p[i]>p[i-1] and p[i]>p[i+1]:
            print("YES")
            print(i-1, i, i+1)
            break
    else:
        print("NO")