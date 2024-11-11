R=lambda:list( map(int,input().split()) )
 
TC,=R()
while TC:
    A=[]
    TC=TC-1
    w,h = R()
    l1=R()[1:]
    l2=R()[1:]
    l3=R()[1:]
    l4=R()[1:]
    
    MH=max(l3+l4)
    MW=max(l1+l2)
    
    A.append( (max(l1)-min(l1)) * max(MH,h)   )
    A.append( (max(l2)-min(l2)) * max( abs(MH-h), h    ) )
    A.append(   (max(l3)-min(l3)) * max(MW, w)              )
    A.append( (max(l4)-min(l4)) * max( abs(MH-w), w    ) )
    print(max(A))