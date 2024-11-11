for _ in range(int(input())):
    n = int(input())
    a=[]
    cnt,i =1,1
    while(cnt<=n):
        if(i%3!=0 and i%10!=0):
            a.append(i)
            cnt+=1
        i+=1
    print(a[-1])