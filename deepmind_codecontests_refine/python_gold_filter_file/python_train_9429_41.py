n=int(input())
l=list(map(int,input().split()))
l.sort()
for i in range(n-2):
    if l[i]+l[i+1]>l[i+2]:
        print("YES")
        break
else:
    print("NO")
