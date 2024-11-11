import sys
t=int(input())
for i in range(t):
    l,r,m=map(int,input().split())
    a=l
    while True:
        if m<a:
            diff = (a-m)
            if diff<=(r-l):
                c=r
                b=c-diff
                if b<=r and b>=l:
                    sys.stdout.write(str(a)+' '+str(b)+' '+str(c)+'\n')
                    break
        else:
            diff1=m%a
            diff2=a-diff1
            #print(diff1,diff2,r-l)
            if diff1<=(r-l):
                b=r
                c=b-diff1
                if c<=r and c>=l:
                    sys.stdout.write(str(a)+' '+str(b)+' '+str(c)+'\n')
                    break
            if diff2<=(r-l):
                c=r
                b=c-diff2
                if b<=r and b>=l:
                    sys.stdout.write(str(a)+' '+str(b)+' '+str(c)+'\n')
                    break
        a+=1
            
