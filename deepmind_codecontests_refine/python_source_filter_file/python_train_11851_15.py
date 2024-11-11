n=int(input())
if n==3:
    ans=[2,5,63]
elif n==4:
    ans=[2,5,20,63]
elif n==5:
    ans=[2,4,6,3,9]
elif n==6:
    ans=[2,4,6,3,9,24]
else:
    for i in range(15000,0,-3):
        if n-i>0 and (n-i)%2==0:
            m2=i
            m3=n-i
            break
    m5=0
    if m3*6-3>30000:
        while m2%5>0:
            m2-=6
            m5+=6
        while m3%5>0:
            m3-=6
            m5+=6
    ans=[]
    for i in range(2,m2*2+1,2):
        ans.append(i)
    for i in range(3,m3*6,6):
        ans.append(i)
    for i in range(5,m5*5,30):
        ans.append(i)
print(" ".join(map(str,ans)))