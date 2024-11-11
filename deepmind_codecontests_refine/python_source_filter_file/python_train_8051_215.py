n=int(input(""))
liste=input("").rsplit()
liste2=list()
for i in liste:
     liste2.append( int(i) )
print("{:3.4f}".format( sum (liste2) / n * 100  )  )