n=int(input())
for i in range(n//4):
    if (n-4*i)%7==0:
        print("Yes")
        exit()
print("No")