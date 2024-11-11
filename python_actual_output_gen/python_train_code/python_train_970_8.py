def lucky(h,m):
    a=str(h)
    b=str(m)
    if('7' in a or '7' in b):
        return 1
    else:
        return 0
    
x=int(input())
h,m=input().strip().split(' ')
h,m=[int(h),int(m)]
cnt=0
while(not lucky(h,m)):
    m-=x
    cnt+=1
    if(m<=0):
        m+=60
        h-=1
    if(h<=0):
        h+=24
print(cnt)
