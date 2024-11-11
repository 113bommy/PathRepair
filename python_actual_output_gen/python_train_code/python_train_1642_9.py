a=input()
b=["a","e","i","o","u","y","A","E","I","O","U","Y"]
a.replace(" ","")
if a[len(a)-2] in b :
    print("YES")
else :
    print("NO")
