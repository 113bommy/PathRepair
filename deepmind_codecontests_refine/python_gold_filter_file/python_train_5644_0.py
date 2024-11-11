n,m = map(int,input().split())
s = input()
s1 = s[:m]
s2 = ""
for i in range(n):
    s2+= s1[i%m]
print(n)
if s2>=s:
    print(s2)
else:
    j = m-1
    while s1[j]=='9':
        j-=1
    s1= s1[:j]+chr(ord(s1[j])+1)
    s1+= '0'*(m-len(s1))
    s2=""
    for i in range(n):
        s2+= s1[i%m]
    print(s2)