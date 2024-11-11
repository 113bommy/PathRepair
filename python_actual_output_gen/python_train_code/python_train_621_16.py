n,k  = map(int,input().split())
s = input()
res = 0
for i in range(1,n):
    if s[i] == s[i-1]:
        res += 1

print (res+k*2)