n = int(input())
ans = 0
for i in range(n):
    a , b = map(int, input().split() )
    if i==0:
        t = max(a,b)
    else:
        x = max(a,b)
        if x<=t:
            temp=x
        else:
            temp = min(a, b)
        if temp>t:
            print("NO")
            ans =1
            break
        else:
            t=temp

if ans==0:
    print("YES")