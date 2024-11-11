# """
# PROG:ride
# ID: taranri1
# LANG: PYTHON3
# TASK: ride
# """
# fin=open('ride.in','r')
# a=fin.readline()
# # a,b=map(str,fin.readline())
# b=fin.readline()

# val=1
# val2=1
# for i in a:
#     val*=(ord(i)-64)
# for i in b:
#     val2*=(ord(i)-64)
# out=open('ride.out','w')
# if val%47==val2%47:
#     out.write(str("GO")+'\n')
#     out.close()
# else:
#     out.write(str("STAY")+'\n')
#     out.close()
for t in range(int(input())):
    x=[int(i) for i in input().split()]
    n,m=x[0],x[1]
    if n==m:
        print(n%10)
        continue
    if n<m:
        print(0)
        continue
    x=m
    dp=[0]*10
    sumo=0;sumo2=0
    accnt=n//m;cnt=0
    while dp[m%10]!=1 and m<=n:
        dp[m%10]=1
        sumo2+=m
        sumo+=m%10
        m=m+x
        cnt+=1
    ans=sumo*((accnt)//cnt)
    # print(ans)
    m=x*(accnt//cnt)*(cnt)+x
    # print(m,ans)
    while m<n:
        if m%x==0:
            ans+=m%10
        m+=x
    print(ans)


