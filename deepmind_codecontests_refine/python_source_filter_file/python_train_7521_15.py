if __name__ == "__main__": 
    tc=int(input())
    while tc>0:
        tc-=1
        n=int(input())
        a=list(map(int,input().rstrip().split()))
        s="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
        print(s)
        for i in range(n):
            temp=a[i]
            if s[temp]!="x":
                print(s[:temp],end="")
                print("x",end="")
                print(s[temp+1:])
                s=s[:temp]+"x"+s[temp+1:]
            else:
                print(s[:temp],end="")
                print("y",end="")
                print(s[temp+1:])
                s=s[:temp]+"x"+s[temp+1:]
        