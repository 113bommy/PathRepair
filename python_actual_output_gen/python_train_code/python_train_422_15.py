r=input()
lst = input()
a="qwertyuiopasdfghjkl;zxcvbnm,./"
lst2=[]
if r=="R":
    for i in range(len(lst)-1):
        c=a.find(lst[i])
        lst2.append(a[c-1])
if r=="L":
    for i in range(len(lst)-1):
        c=a.find(lst[i])
        lst2.append(a[c+1])
s = ""
print (s.join(lst2))
