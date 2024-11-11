a,b=input().split(":")
a,b=int(a),int(b)
c=int(input())
e,f,c,d=0,0,c//60,c%60
b,e=(b+d)%60,(b+d)//60
a=(a+c)%24+e
print('0'*(a<10)+str(a)+":"+"0"*(b<10)+str(b))
   