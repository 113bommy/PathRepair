n=int(input())
l=list(map(int,input().split()))
m=min(l)
x=l.count(m)
if x>1:
    print("Still Rozdil")
else:
    print(l.index(m) + 1)