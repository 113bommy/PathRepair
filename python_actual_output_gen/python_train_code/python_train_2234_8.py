num = int(input())
turns = num-11
s = str(input())
v = (num-11)//2
p = (num-11)//2
res = ""
for i in range(num):
    if s[i]=="8":
        if v>0:
            v-=1
        else:
            res+=s[i]
    else:
        if p>0:
            p-=1
        else:
            res+=s[i]
    print(res)
    
print("YES" if res[0]=="8" else "NO")
