import sys

n,m,l = list(map(int,sys.stdin.readline().split()))
arr = list(map(int,sys.stdin.readline().split()))
temp = []
ans = 0
f = 0

for i in arr:
    if i>l:
        temp+=[1]
    else:
        temp+=[0]

for i in range(n):
    if temp[i]==1 and f==0:
        f = 1
        ans+=1
    elif temp[i]==1 and f==1:
        pass
    elif temp[i]==0:
        f = 0

for i in range(m):
    x = sys.stdin.readline()
    if x[0]=='0':
        print(sys.stdout.write(str(ans)+'\n'))
    else:
        _,p,d = list(map(int,x.split()))
        p-=1
        if p-1<0:
            low = False
        else:
            low = True
        if p+1<n:
            high = True
        else:
            high=False
        if temp[p]==0 and arr[p]+d>l:
            temp[p] = 1
            if low and high:
                if temp[p-1]==0 and temp[p+1]==0:
                    ans+=1
                elif temp[p-1]==1 and temp[p+1]==1:
                    ans-=1
            elif not low and not high:
                if ans==0:
                    ans+=1
            elif p==0:
                if high:
                    if temp[p+1]==0:
                        ans+=1
            elif p==n-1:
                if low>-1:
                    if temp[p-1]==0:
                        ans+=1
        else:
            arr[p]+=d
        # print(temp)
                