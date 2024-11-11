str1 = input()
str2 = input()
ind  = 0
for ch in str2:
    if(ch == str1[ind]):
        ind+=1
print(ind)