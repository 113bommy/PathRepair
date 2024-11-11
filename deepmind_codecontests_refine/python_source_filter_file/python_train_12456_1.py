n=int(input())
ar=list(map(int,input().split()))
for i in range(n):
    if ar[ar[ar[i]-1]-1]==ar[i]:
        print("YES")
        break
else:
    print("NO")
        