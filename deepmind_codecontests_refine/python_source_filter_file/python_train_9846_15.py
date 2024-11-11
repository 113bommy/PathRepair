n = int(input()) ;
L =  list( map(int,input().split()) ) ;
mx = max(L) ;
print( sum( [ mx - L[i] for i in L ] ) )