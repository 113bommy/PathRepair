from sys import stdin

s=[]
w=9
b=9
w1=[]
b1=[]
s1=[]
for i in range(8):
    s=stdin.readline().strip()
    s1.append(s)
    for j in range(8):
        
        if "W" ==s[j] and j not in b1 :
            w=min(w,i)
        if "B" == s[j]:
            b1.append(j)
s1.reverse()
for i in range(8):
    s=s1[i]
    for j in range(8):
        
        if "B" ==s[j] and j not in w1 :
            b=min(b,i)
        if "B" == s[j]:
            w1.append(j)
if w<=b:
   print("A")
else:
    print("B")
