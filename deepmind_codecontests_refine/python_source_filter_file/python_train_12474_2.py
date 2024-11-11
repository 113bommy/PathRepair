s=input()
w=int(input())
a=[]
for i in range(len(s)):
  if (i+1)%w==1:a.append(s[i])
print(''.join(a))