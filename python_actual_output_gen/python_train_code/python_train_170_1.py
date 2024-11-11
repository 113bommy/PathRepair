a,b,c,d,e=map(int,input().split()) 
dis=(e-c)**2 + (d-b)**2
dis=dis**(0.5)
print (int(dis//(2*a)) if dis%a==0 else int(dis//(2*a)) +1)