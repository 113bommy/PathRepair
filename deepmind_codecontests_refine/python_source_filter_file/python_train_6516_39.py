s='';a=['a','b','b','c']
for i in range(1,int(input())+1):
    c=i%4
    s+=a[c]
print(s)