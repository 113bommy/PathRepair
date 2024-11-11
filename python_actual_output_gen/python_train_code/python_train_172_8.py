m= input().split()
w=input().split()
h=input().split()
s=int(h[0])*100-int(h[1])*50
x=500
for i in range(5):
    s+=max(.3*x,(1-int(m[i])/250)*(x*(i+1))-50*int(w[i]))
print(int(s))
