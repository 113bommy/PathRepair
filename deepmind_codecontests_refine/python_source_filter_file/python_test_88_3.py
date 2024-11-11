n = int(input())
for i in range(n):
    a = int(input())
    ar = list(map(int,input().split()))
    if a % 2 ==0:
        print("YES")
        continue
    b = True
    for i in range(a-1):
        if(ar[i] > ar[i+1]):
            b = False
            break
    print("YES" if not b else "NO")