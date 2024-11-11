#input=__import__('sys').stdin.readline
n,x,y = map(int,input().split())
s = list(input())
if s.count('0')==0:
    print(0)
    exit()
s1=s[:]
grp=0
for i in range(1,n):
    if s[i]=='1' and s[i-1]=='0':
        grp+=1
if s[-1]=='0':
    grp+=1
ans = min((grp-1)*x +y , grp*y)            
print(ans)




