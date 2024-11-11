s=input()
count=0
for i in range (len(s)):
    if(s[i]=='a'or s[i]=='e'or s[i]=='i'or                              s[i]=='o'or s[i]=='u'):
        count+=1
    elif(s[i]=='0'or s[i]=='2'or s[i]=='4'or s[i]=='6'or s[i]=='8'):
        count+=1
print(count)