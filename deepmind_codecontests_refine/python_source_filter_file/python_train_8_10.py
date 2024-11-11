n=input()
c=input()
eig_d=c.count('8')
if eig_d==0 or int(n)<8 :
    print(0)
else :
    print(min(eig_d,int(n) // 8)) 
