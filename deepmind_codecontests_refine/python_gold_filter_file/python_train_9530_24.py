n=int(input())
for i in range(n):
    n,b,a=[i for i in input().split()]
    if int(b)>=2400 and int(a)-int(b)>0:
        print("YES")
        break
else:
    print("NO")
