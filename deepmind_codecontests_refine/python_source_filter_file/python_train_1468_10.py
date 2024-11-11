v='aouien'
s=input()+'b'
#print(list(zip(s, s[1:])))
print(('NO','YES')[all(x in v or y in v for x,y in zip(s,s[1:]))])