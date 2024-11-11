z,o,k = map(int,input().split())
if(k==0):
    print("YES")
    print('1'*o + '0'*z)
    print('1'*o + '0'*z)
elif(z==0 or o==0):
    print("NO")
elif(z>=1 and o>=2 and k < z+o-1):
    print("YES")
    z -= 1
    o -= 2
    zz = min(k-1, z)
    oo = min(k-1-zz, o)
    a = '1'*(o-oo) + '11' + '0'*zz + '1'*oo + '0' + '0'*(z-zz)
    b = '1'*(o-oo) + '10' + '0'*zz + '1'*oo + '1' + '0'*(z-zz)
    print(a)
    print(b)
else:
    print("NO")