n=int(input())
a=list(map(int,input().split()))
for i in range(0,len(a)):
    if(a[i]%2!=0):
        print("First")
        break
print("Second")


