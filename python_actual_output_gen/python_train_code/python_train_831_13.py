t=int(input())
a=list(map(int,input().strip().split()))
f=1
for i in a:
    if(i%2!=0):
        print("first")
        f=0
        break
if(f):
    print("second")