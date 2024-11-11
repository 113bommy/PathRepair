n=int(input())
s=input()
t=s
for i in range(n-1):
    if s[i]>=s[i+1]:
        print(s[:i]+s[i+1:])
        exit()
print(s[:-1])