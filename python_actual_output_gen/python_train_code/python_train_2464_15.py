n=int(input())
arr=list(map(int,input().split()))
t=arr.count(5)
p = arr.count(0)
if(p==0):
    print("-1")
elif(t<9):
    print("0")
else:
    t=t//9
    t=t*9
    q=str(5)*t
    q+=str(0)
    print(q)