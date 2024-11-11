a , b = map(int,input().split())
lastDigit = b%10
if lastDigit in [3,5,7,9]:
    print("NO")
else:
    ans = 0
    transform = [b]
    while a < b:
        lastDigit = b % 10
        if lastDigit in [3,5,7,9]:
            print("NO")
            exit()
        ans+=1
        if lastDigit==1:
            b = b//10
            transform.append(b)
        else:
            b//=2
            transform.append(b)
    print(transform)
    if b == a:
        print("YES")
        print(len(transform))
        transform.reverse()
        for i in transform:
            print(i,end=' ')
        print()
    else:
        print("NO")
