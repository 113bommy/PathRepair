N,S=input().split()
ans=1
c=[1]*26
for i in S:
        c[ord(i)-ord('a')]+=1
for i in c:
        ans*=i
print(ans%1000000007-1)