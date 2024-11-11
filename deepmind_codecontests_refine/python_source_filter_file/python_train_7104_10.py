q=int(input())
for i in range(q):
    a,c,b=[int(i) for i in input().split()]
    if c>0:
        s='10'
        if c%2==0:
            s+='10'*max(c//2,0)+'1'
        else:
            s+='10'*max(c//2,0)
        s=s[0]*(b+1)+s[1]*(a+1)+s[2::]
        print(s)
    else:
        if a>0:
            print('0'*(a+1))
        else:
            print('1'*(b+1))