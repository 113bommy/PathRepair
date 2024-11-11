n,a,b=input().split()
n,a,b=int(n),int(a),int(b)
x=n-b
while x:
    if x<=a:
        x+=1
    if x>a and n-x<=b:
        print(n-x+1)
        exit()
    