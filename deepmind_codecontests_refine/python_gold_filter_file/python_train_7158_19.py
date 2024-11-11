n=input()
a=0
for i in range(1,len(n)-1):
    if n[i]!="." and n[i-1]!="." and n[i+1]!="." and n[i]!=n[i+1] and n[i]!=n[i-1] and n[i-1]!=n[i+1]:
        print("Yes")
        a=1
        break
if a==0:
    print("NO")

    
