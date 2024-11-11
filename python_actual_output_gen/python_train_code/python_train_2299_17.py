n=int(input())
l=list(map(int,input().split()))
for i in l:
    if i%2==0 and i%3!=0 and i%5==0:
        print("DENIED")
        exit()
print("APPROVED")