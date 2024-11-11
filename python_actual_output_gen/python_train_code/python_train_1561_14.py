n = input().lower()
x = "aeiouAEIOU"
for i in x:
    for j in n:
        if i == j:
            n = n.replace(i,"")
for x in range(len(n)):
    print("."+n[x],end="")

