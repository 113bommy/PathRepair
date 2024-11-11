n, m=map(int, input(). split())
Mn1 =set(input(). split() ) 
Mn2=set(input(). split() )
Mn3={} 
Mn3=Mn1&Mn2
if Mn3:
    print(int(min(Mn3))) 
    exit() 
mn1=int(min(Mn1)) 
mn2=int(min(Mn2)) 
if mn1==mn2:
    print(mn1) 
elif mn1<mn2:
    print(mn1*10+mn2) 
else:
    print(mn2*10+mn1)  