chars='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_'
mp={}
for i in range(len(chars)):
  mp[chars[i]]=i
zero=0
s=input()
for i in range(len(s)):
  zero+=sum([i=='0' for i in format(mp[s[i]],'06b')])
print(str(pow(3,zero,int(1e9+7))))
