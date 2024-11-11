uv , dv , u = map ( int , input (). split ())
if uv >  dv and dv + u < uv:
    print ( "+" )
elif uv < dv and uv + u < dv:
    print ( "-" )
elif uv == dv and u == 0 :   
    print ( "0" )
else :
    print ( "?" )