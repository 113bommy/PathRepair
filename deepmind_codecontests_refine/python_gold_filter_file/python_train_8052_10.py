n=int(input())
n1=int(input())
n2=7-n1
for i in range(n) :
    l=list(map(int,input().split()))
    if n1 in l or n2 in l :
        print("NO")
        exit()
print("YES")