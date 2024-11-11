for t in range(int(input())):
    x,y = [int(x) for x in input().split(" ")]
    # if (x==0 and y!=0) or (y==0 and x!=0):
    #     print("NO")
    #     continue
    if x==0 and y==0:
        print("YES")
        continue
    a = (2*y-x)//3
    b = (2*x-y)//3
    if a+2*b==x and 2*a+b==y and b>0 and a>0:
        print("YES")
    else:
        print("NO")