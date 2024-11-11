for _ in range(int(input())):
    x,y=[int(x) for x in input().split()]
    s=input()
    b=s.count('0')-s.count('1')
    z,ans=0,0
    flag=False
    if x==1:ans=1
    for i in s:
        z+=(i=='0')-(i=='1')
        if b==0 and z==y:
            flag=True
            print(-1)
            break
        if z==y or  ((y-z)*b >0 and abs((y-z))%abs(b)==0):ans+=1
    
    if not flag:print(ans)


