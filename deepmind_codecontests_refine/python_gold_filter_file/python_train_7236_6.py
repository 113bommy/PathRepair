def fun(x,y,z):
    a,b,c,d,e,f=aa[x]+aa[y]+aa[z]
#    print(a,b,c,d,e,f)
    return (a==c and not (b<f<d or d<f<b)) or (b==d and not(a<e<c or c<e<a))
inn=lambda:map(int,input().split())
aa=[list(inn()),list(inn()),list(inn())]
#print(aa)
if aa[0][0]==aa[1][0]==aa[2][0] or aa[0][1]==aa[1][1]==aa[2][1]:
    print(1) 
elif fun(0,1,2) or fun(1,2,0) or fun(0,2,1):
    print(2)
else:
    print(3)    



