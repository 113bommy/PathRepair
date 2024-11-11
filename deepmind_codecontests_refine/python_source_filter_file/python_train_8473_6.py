n=int(input())
l=sorted(map(int,input().split()))
for i in range(n//3):
    if not l[i]<l[i+n//3]<l[i+2*(n//3)] or l[i+n//3]%l[i]!=0 or l[i+2*(n//3)]%l[i+(n//3)]:
        print(-1)
        exit(0)

for i in range(n//3):
    print(l[i::n//3])