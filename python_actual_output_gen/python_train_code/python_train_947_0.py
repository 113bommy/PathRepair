n=int(input())
a=list(map(int,input().split()))
s=0
if max(a)<=0:
    print(abs(abs(sum(a)) + 2*max(a)))
elif min(a)>=0:
    print(abs(abs(sum(a)) - 2*min(a)))
else:
    for i in a:
        s+=abs(i)
    print(s)
    
    