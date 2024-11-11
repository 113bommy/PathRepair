s=input()
c=0
s2=""
s3=""
for i in s:
 s3+=i
 if s2!=s3:
  c+=1
  s2+=s3
  s3=""
print(c)