def check(n):
    if n[0] != "1":
        return "NO"
    for i in n:
        if i != "1" or i != "4":
            return "NO"
    if "444" in n:
        return "NO"
    return "YES"
    
 
 
n = input()
print(check(n))
