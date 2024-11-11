i = int(input())
for j in range(0,i):
    n = int(input())
    ans = 0
    for k in range(0,(1+(n-3)//2)+1):
        ans+= 8*i*i
    print(ans)