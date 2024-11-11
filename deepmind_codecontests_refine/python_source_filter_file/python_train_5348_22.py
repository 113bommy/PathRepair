s=input()
j=s.find('0')
print(j)
if j==-1:
    print(s)
else:
    h=s[:j]+s[j+1:]
    print(h)
