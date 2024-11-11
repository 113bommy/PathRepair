n=int(input())
l=list(map(int,input().split()))
if l.count(1)==0:
    print(0)
elif l.count(2)>=l.count(1)  :
    print(l.count(2))
else :
    print(l.count(2)+(l.count(1)-l.count(2))//3)
