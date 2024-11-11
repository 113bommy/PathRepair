n=int(input())
s=list(map(int, input().split()))
x=abs(s[0])
for i in range(1,n):
    x+=abs(s[i]-s[i-1])
print(x)
