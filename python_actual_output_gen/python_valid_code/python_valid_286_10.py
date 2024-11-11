s = input()
k = (sorted(s , reverse = True))
print(k)
i = 0
print(k[0],end="")
while k[i] == k[i+1] :
    print(k[i] ,end = "")
    i += 1