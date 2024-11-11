n=int(input())
s=input()
c=0
for i in range(n,len(s),n):
    if s[i-1]+s[i-2]+s[i-3] in ['aaa','bbb']: c+=1
print(c)
