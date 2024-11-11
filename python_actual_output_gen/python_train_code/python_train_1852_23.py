s=input()
j=s.find('0')
#print(j)
if j==-1:
    print(s)
else:
    r=s[:j]+s[j+1:]
    print(r)
