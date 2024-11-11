s = input()
n = len(s)

i = 0
string = ""
count = 0
while(i < n):
    st = s[i : i + 3]
    if(st == "WUB"):
        count += 1
        
        if(count == 1):
            string = string + " "
        i += 3
    else:
        count = 0
        string = string + s[i]
        i += 1
        
string = string.lstrip()
print(string)