import sys
input=sys.stdin.buffer.readline
inin=lambda: int(input())
inar=lambda: list(map(int,input().split()))
inst=lambda: input().decode().rstrip('\n\r')

for _t_ in range(inin()):
    n=inin()
    s=list(inst())
    if len(set(s))==1:
        print(n//3 + 1)
        continue
    else:
        i=0
        while(s[i]==s[-1]):
            s.append(s[i])
            i+=1
        s=s[i:]
        ans=0
        cnt=0
        prev=' '
        #print(s)
        for i in s:
            #print(i,prev)
            if i==prev:
                cnt+=1
            else:
                ans+=(cnt//3)
                cnt=1
                prev=i
        ans+=cnt//3
        print(ans)

