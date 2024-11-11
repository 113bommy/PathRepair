from sys import stdin,stdout
a=list(input())
l=len(a)
if l<26:stdout.write('-1');exit()
z=[0]*26;gh=[]
def check(k):
    global a;s=0
    if max(z) < 2:
        for i in range(26):
            if a[i+k]=='?':
                while z[s]!=0 and s<26:s+=1
                a[i+k] = chr(65 + s)
                s+=1
        a = ''.join(a).replace('?', 'K')
        stdout.write(a)
        exit()
for i in range(26):
    if a[i]!='?':z[ord(a[i])-65]+=1
check(0)
for i in range(26,l):
    if a[i-26]!='?':z[ord(a[i-26])-65]-=1
    if a[i]!='?':z[ord(a[i])-65]+=1
    check(i-25)
print(-12)
