for _ in range(int(input())):
    s=input()
    #n=int(input())
    #a,b= map(int, input().split())
    #arr=list(map(int, input().split()))
    a=0
    b=0
    aa=0
    bb=0
    ans=10
    for i in range(10):
        if i%2:
            if s[i]=="1":
                b+=1
            elif s[i]=="?":
                bb+=1
            c = (10 - i-1) //2
            if (10 - i - 1) % 2:
                c += 1
            z=(10-i-1)//2
            if b+bb>=a+c:
                ans=i+1
                break
            if a+aa>=b+c-1:
                ans=i+1
                break
            

        else:
            if s[i]=="1":
                a+=1
            elif s[i]=="?":
                aa+=1
            c = (10 - i-1) //2
            if (10 - i - 1) % 2:
                c += 1
            z=(10-i-1)//2
            if aa+a>=b+c:
                ans=i+1
                break
            if bb+b>=a+z:
                ans=i+1
                break
        #print( a,b)
    print(ans)