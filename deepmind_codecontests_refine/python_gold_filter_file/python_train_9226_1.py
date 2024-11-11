n=int(input())
for _ in range(n):
    x=int(input())
    if x%3==0:
        print("YES")
        continue
    if x%7==0:
        print("YES")
        continue
    l=x
    while l>=0:
        if l%7==0:
            print("YES")
            break
        l-=3
    else:
        l=x
        while l>=0:
            if l%3==0:
                print("YES")
                break
            l-=7
        else:
            print("NO")
