n=int(input())
s=input()
if s==sorted(s):
    print("NO")
else:
    flag=0
    for i in range(n-1):
        if s[i]>=s[i+1]:
            flag=1
            break
    if flag==1:
        print("YES")
        print(i+1,i+2)

    else:
        print("NO")
