n = int (input())
for i in range(1,n+1):
    if n ==i*(i+1)//2 :
        print("yes")
        exit()
print("no")