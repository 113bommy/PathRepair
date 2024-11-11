keys = "qwertyuiopasdfghjkl;zxcvbnm,./"
m = input()
t = input()
if m == "R":
    k=-1
else:
    k=1
    
for i in range(len(t)):
    print(keys.index(t[i])+k,end="")