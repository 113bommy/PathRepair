s = list(input())
k = int(input())
ans=[]
for c in s:
    if (ord('a')-ord(c))%26 <= k:
        ans.append('a')
        k-=(ord('a')-ord(c))%26
    else:
        ans.append(c)
ans[-1]=chr(ord(ans[-1])+k)
print(''.join(ans))
