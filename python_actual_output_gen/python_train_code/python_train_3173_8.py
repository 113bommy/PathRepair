n = int(input())
for i in range(n):
    p = int(input())
    j=0
    temp=True
    while p-7*j>=0:
        if (p-7*i)/3 == (p-7*i)//3:
            print("YES")
            temp=False
            break
        j+=1
    if temp:
        print("NO")