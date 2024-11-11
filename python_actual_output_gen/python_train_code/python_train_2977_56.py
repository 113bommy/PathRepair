s=input()
k=0
for i in range(len(s)):
    if s[i]=='a':
        k+=1
if k==len(s):
    print(k)
elif len(s)-k<k:
    print(k)
else:
    print(k*2-1)