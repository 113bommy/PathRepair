n = int(input()) ;
L =  list( map(int,input().split()) ) ;
mx = max(L) ;
print( sum( [ mx - x for x in L ] ) )
