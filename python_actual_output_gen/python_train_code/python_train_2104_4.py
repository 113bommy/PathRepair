n=int(input()) 
a=list(map(int,input().split())) 
if(n%2==0 and a[0]%2==0 and a[-1]%2==0):
    print("YES") 
else:
    print("NO") 
    