n = input()
w = input()
s =""
vowels = ["a","e","i","o","u"]
s=s+w[0]
c = 1 if s in vowels else 0
for l in w[1:]:
    d = 1 if l in vowels else 0
    if c and d:
        continue
    else:
        s=s+l
    c=d
        
print(s)
    
        
        