



t = int(input())
for i in range(t):
    a = list(input())
    b = list(input())
    c = list(input())
    if a==b or c==b:
        print("YES")
    else:

        ans = True
        for i in range(len(a)):
            if a[i]!=c[i] and c[i]!=b[i]:
                ans = False
                break
        if not ans:
            print("NO")
        else:
            print("YES")










