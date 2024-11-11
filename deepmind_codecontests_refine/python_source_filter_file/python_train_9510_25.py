n=int(input())
li=input().split()
l=list(map(int,li))
low=min(l)
if(l.count(low)>=2):
    print("Still Rodzil")
else:
    print(l.index(low))
