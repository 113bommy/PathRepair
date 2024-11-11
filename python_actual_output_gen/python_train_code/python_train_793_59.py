n,k=map(int,input().split())
s=input()

a=(s[n-2]).lower()

print(s[0:n-2] + a + s[n-1:])