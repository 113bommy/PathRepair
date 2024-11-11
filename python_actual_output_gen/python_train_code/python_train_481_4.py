for _ in range(int(input())):
    a=input()
    b=input()
    c=input()
    for i in range(len(a)):
        if a[0]!=b[0] and b[0]!=c[0] and c[0]!=a[0]:
            print("NO");break
        elif a[i]==b[i] and a[i]!=c[i]:
            print("NO")
            break
    else:print("YES")