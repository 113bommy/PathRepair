n=int(input())
s=input()
for i in range(1,n):
    if s[i]<s[i-1]:
        print("YES")
        print(i-1,i)
        exit(0)
print("NO")
    