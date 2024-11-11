a,b,c=map(int,input().split())
for i in range(a):
    for j in range(b):
        if (a-i)*b+(b-j)*a==c:
            print('Yes')
            exit()
print('No')