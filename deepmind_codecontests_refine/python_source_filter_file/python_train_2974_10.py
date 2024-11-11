b = int(input())
a = input()
s = ''
for i in range(len(a)):
    s+=a[i]
    q = s.find('ogo')
    if q!=-1:
       s=s[:q]+'***'
    q = s.find('*go')
    if q!=-1:
        s=s[:q]+'**'
print(s)
        