a=input()
n=len(a)
b=a[0:n-1]
c=b.strip()
if c[-1]=='a' or c[-1] =='e' or c[-1]=='i' or c[-1]=='o' or c[-1]=='u' or c[-1]=='y' :
    print("YES")
else:
    print("NO")
    
