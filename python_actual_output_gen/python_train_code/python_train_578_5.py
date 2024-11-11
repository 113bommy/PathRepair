n = int(input())
a = [int(x) for x in input().split()]
s = sum(a)
if s!=0:
    print("YES")
    print(1)
    print(1,n)
else:
    if a[0]!=0:
        print("YES")
        print(2)
        print(1,1)
        print(2,n)
    else:
        j=0
        while a[j]==0:
            j+=1
            if j==n: break
        if j==n:
            print("NO")
        else:
            print("YES")
            print(2)
            print(1,j)
            print(j+1,n)
