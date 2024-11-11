s = input()
char = "qwertyuiopsdfghjklzxcvnmñ"
for i in range(len(char)):
    s = s.replace(char[i],"")

count = 0
total = []
sol =1
for i in range(len(s)):
    if s[i] == "a" :
        count+=1   
    if s[i] == "b" or i == len(s)-1:
        total += [count]
        count =0 
for i in total:
    sol = sol*(i+1)



    
   
print((sol-1)%(10^7 + 9)) 