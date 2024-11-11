n=int(input())
li=list(map(int,input().split()))
li.sort()
if li[(n//2)-1]!=li[n//2]:
    print("YES")
else:
    print("NO")
