li=[str(x) for x in input()]
if 'h' in li:
     a1=li.index('h')
     li=li[(a1):]
     if 'e' in li:
         a2=li.index('e')
         li=li[(a2):]
         if 'l' in li:
             a3=li.index('l')
             li=li[(a3):]
             if 'l' in li:
                 a4=li.index('l')
                 li=li[(a4):]
                 if 'o' in li:
                     print('YES')
                 else:
                     print('NO')
             else:
                  print('NO')
         else:
               print('NO')
     else:
            print('NO')
else:
     print('NO')