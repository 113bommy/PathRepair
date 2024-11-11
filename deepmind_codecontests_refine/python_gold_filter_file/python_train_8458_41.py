t=int(input())
#print('**********')
while t>0:
    t-=1
    n=int(input())
    arr=list(map(str,input().split()))
    num=set()
    ans=''
    for i in arr:
        if i not in num:
            num.add(i)
            ans+=i+' '
    print(ans)

