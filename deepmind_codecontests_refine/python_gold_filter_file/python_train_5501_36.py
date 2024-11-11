a,b,c=map(int,input().split())
for i in range(a+1):
    for j in range(b+1):
        if (a-i)*j+(b-j)*i==c:
            print('Yes')
            exit()
print('No')