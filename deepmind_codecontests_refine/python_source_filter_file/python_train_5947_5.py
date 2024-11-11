n=int(input())
s=input()
if n>1:
    for i in range(n-1):
        if s[i]<s[i+1]:
            print("YES")
            print(s[i:i+2]);break
    else:print("NO")
else:print("NO")