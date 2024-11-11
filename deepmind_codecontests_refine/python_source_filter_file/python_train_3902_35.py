m,n = input().split()

m,n = int(m), int(n)

for i in range(n):
    a = i+1
    if (a%2==0):
        if a%4==0:
            print("#" + "."*(m-1))
        else:
            print("."*(m-1) + "#")
    else:
        print("#"*m)