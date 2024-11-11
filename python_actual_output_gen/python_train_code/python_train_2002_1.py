n=int(input())
if n==1:
    print("1")
    print("1")
elif n==2:
    print("1")
    print("1")
    
elif n==3:
    print("2")
    print("1 3")
elif n==4:
    print("3")
    print("3 1 4 2")
else:
    print(n)
    even=[]
    odd=[]
    for i in range(1,n+1):
        if i%2==0:
            even.append(i)
        else:
            odd.append(i)
    print(*odd,end=' ')
    print(*even)
