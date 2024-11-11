for i in range(int(input())):
    n=int(input())
    s=input()
    if(len(s)==2 and s[0]<=s[1]):
        print("NO")
    else:
        print("YES")
        print(2)
        print("{} {}".format(s[0],s[1:]))
