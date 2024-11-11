s=input()
l=s.lower()

v=['a','e','i','o','u']
r=''
for i in l:
    if i not in v:
       r+='.'+i
print(r)
