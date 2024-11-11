m = input()
ans = ""
i = 0
while i < len(m):
    if m[i] == ".":
        ans += "0"
    elif m[i] == "-" and m[i+1] == ".":
        ans += "1"
        i += 1
    elif m[i] == "-" and m[i+1] == "-":
        ans += "2"
        i += 1
    
    i += 1

 
print(ans)