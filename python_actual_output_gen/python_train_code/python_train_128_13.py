a = int(input());
b = int(input());
c = 0;
d =1;
if ( a < b):
    while ( a < b ):
            b -= 1;
            c += d;
            if ( a < b ):
                    b -= 1;
                    c += d;
                    d += 1;
            else:
                    break;
else:
    while ( a > b ):
            b += 1;
            c += d;
            if ( a < b ):
                    b += 1;
                    c += d;
                    d += 1;
            else:
                    break;
print(c);