x=input()
ans=[]
m=['a','e','i','o','u','y']
for i in x:
    if i.lower() not in m:
        ans.append(i.lower())
# print(*ans,sep='.')
a='.'
for i in ans:
    a+=i+'.'
print(a)