n=int(input())
k=0
list_=[]
if n==1:
    print("NO")
else:
    for i in range(n):
        k=k+i
        list_.append(k)
    if n in list_:
        print("YES")
    else:
        print("NO")