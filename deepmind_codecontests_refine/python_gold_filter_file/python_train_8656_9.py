t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    d=s.find("8")
    if(d==-1):
        print("NO")
    elif(n-d>=11):
        print("YES")
    else:
        print("NO")