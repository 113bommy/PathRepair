try:
    t=int(input())
    for i in range(t):
        n=int(input())
        a=n%10
        c=0
        while n!=0:
            c+=1
            n=n//10
        c=(c*(c+1))/2
        res=c+(a-1)*10
        print(res)
except:
    pass