n = int(input())
a = []
a2 = []
if n%2==0:
    print("NO")
else:
    for i in range(2*n):
        if i%2==0 or i%2==3:
            a.append(i+1)
        else:
            a2.append(i+1)
    print("YES")
    print(*(a+a2))