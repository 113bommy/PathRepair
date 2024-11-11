n=int(input())
c=1
for i in range(4,n+1):
    if n%i==0:
        s=str(i)
        for j in s:
            c=0
            if j!="4" and j!="7":
                c=1
                break
        if c==0:
            break
if c==0:
   print("YES")
else:
   print("NO")        