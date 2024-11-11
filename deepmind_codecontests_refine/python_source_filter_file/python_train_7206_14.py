t=input()
t=int(t)
for i in range(0,t):
    the_string = input()
    a,b,x,y = the_string.split()
    a,b,x,y=int(a),int(b),int(x),int(y)
    a1=(x*b)
    a2=(y*a)
    a3=(b-x-1)*a
    a4=(a-y-1)*b
    print(max(a1,a2,a3,a4))
    
   
    
    
