n=int(input())
a= [int(input()) for i in range(n)]
for i in a:
    if i%2!=0:
        print("first")
        exit(0)
print("second")