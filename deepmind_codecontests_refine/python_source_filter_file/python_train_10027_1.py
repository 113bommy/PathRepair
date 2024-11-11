t=int(input())
for i in range(t):
    a, b = input().split()
    a1=int(a);
    b1=int(b);
    if b==1:
        print("NO")
    else:
        print("YES")
        print(2*(a1*b1)-a1 ,end=" ")
        print(a1,end=" ")
        print(2*(a1*b1))

