q=int(input())
for i in range(q):
    x=int(input())
    str=input()
    if(x==2 and str[1]==str[0]):
        print("NO")
    else:
        print("YES")
        print("2")
        print(str[0],end=' ')
        for i in range(x-1):
            print(str[i+1],end='')
        print()
    