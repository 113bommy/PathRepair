n=int(input())
s=input()
for i in range(n-1):
    if s[i+1]<s[i]:
        print("YES")
        print(i+1,i+2)
        break
    else:
        print("NO")