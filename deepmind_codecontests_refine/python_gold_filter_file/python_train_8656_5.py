T=int(input())
for t in range (0,T) :
    n=int(input())
    s=str(input())
    if n<=10 :
        print("NO")
    elif n==11 and s[0]=="8" :
        print("YES")
    elif n==11 and s[0]!="8" :
        print("NO")
    elif n>11 :
        for i in range (0,len(s)-10) :
            if s[i]=="8" :
                print("YES")
                break
        else :
            print("NO")
