n,d=map(int, input().split())
l =list(map(int, input().split()))

c=1
if n==1:
    print(2)

else:
    for i in range(1,len(l)):
            if l[i]-l[i-1] >=d*2 :
                c=c+1
            if l[i]-l[i-1] >d*2:
                c=c+1   
    c=c+1
    print(c)
    

