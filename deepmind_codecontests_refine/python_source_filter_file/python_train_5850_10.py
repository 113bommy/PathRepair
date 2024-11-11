n=int(input())
for i in range(n):
    a,b,c=map(int,input().strip().split())
    s=(a+b+c)/3
    if s<=a:
        if s<=b:
            print(int(s))
        else:
            print(b)
    else:
        print("0")
    
