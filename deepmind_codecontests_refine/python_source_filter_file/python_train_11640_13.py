N=int(input())
H=list(map(int,input().split()))
a=0
for i in range(1,N-1):
    if a<H[i-1]:
        a=H[i-1]
    if a-1>H[i+1]:
        print("No")
        break
else:
    print("Yes")