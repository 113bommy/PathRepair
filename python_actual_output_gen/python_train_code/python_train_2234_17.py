n=input()
n=int(n)
s=input()
temp = n%11
eights = (temp/2)+1
turns = temp/2
index = eights + turns
index=int(index)
aux = s[:index]
if aux.count('8')>=eights:
    print("YES")
else:
    print("NO")
