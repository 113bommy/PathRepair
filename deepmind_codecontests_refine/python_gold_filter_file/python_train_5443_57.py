for _ in range(int(input())):
    l,r=map(int,input().split()) 
    if(r>=2*l):
        print("NO")
    else:
        print("YES")