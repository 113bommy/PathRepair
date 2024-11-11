s=input()
ans=s.count('VK')
s.replace('VK','')
if ('VV' in s) or ('KK' in s):
    ans=ans+1
print(ans)