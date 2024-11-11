n=int(input())
l=list(map(int,input().split()))
if n<2:
    print(1)
elif n==2 and l[0]==l[1]:
    print("Still Rozdil")
else:
    if l.count(min(l))>1:
        print("Still Rozdil")
    else:
        print(l.index(min(l))+1)