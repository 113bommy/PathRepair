from sys import stdin
s=stdin.readline()
s.rstrip('\n')
ans=0
n=len(s)
for i in range(1,n):
    if int(s[i-1:i+1])%4==0:
        ans+=i
ans+=s.count('0')+s.count('4')+s.count('8')
print(ans)

        
