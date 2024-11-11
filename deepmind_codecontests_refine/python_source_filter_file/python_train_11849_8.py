n,s=open(0);a=1
for c in set(s):a*=s.count(c)+1
print(~-a%(10**9+7))