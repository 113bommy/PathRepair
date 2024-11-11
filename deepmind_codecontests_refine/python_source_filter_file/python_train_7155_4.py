
a=input()
n=len(a)
w=0
for i in range(n-2):
    s=a[i]+a[i+1]
    s=s+a[i+2]
    if "A" in s and "B" in s and "C" in s:
        print("Yes")
        w=1
        exit
if w==0:
    print("No")
    
    
    
                             