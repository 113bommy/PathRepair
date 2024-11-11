import sys
input=sys.stdin.readline
n=int(input())
ar=list(map(int,input().split()))
ar.sort()
se=set(ar)
li=[]
st=1
for i in range(30):
    li.append(st)
    st<<=1
ans=1
br=[ar[0]]
for i in ar:
    for j in li:
        if(i+j in se):
            if(ans<2):
                ans=2
                br=[i,i+j]
            if(i+2*j in se):
                if(ans<3):
                    ans=3
                    br=[i,i+j,i+2*j]
print(ans)
print(*br)
