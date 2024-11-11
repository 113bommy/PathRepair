s=input()
cnt=0
for i in s:
  if i in "aeiou02468":
    cnt+=1
print(cnt)