n=int(input())
a=list(map(int,input().split()))
if a.count(0)==len(a) :
    print("0")
else :
    for i in range(a.count(0)) :
        a.remove(0)
    print(len(a))
