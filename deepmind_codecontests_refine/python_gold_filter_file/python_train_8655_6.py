s = input()
cnt=0
for i in s:
    if i=='a':
        cnt+=1
if((cnt*2)<=len(s)):
    print((2*cnt)-1)
else:
    print(len(s))
