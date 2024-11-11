from bisect import*;input();l,*a=[],
for c in[-ord(i)for i in input()]:
 i=bisect_left(l,c);a+=i,
 if i<len(l):l[i]=c
 else:l+=c,
print(len(l))
print(*a)