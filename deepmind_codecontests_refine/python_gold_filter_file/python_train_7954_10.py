s = input();

sumleft = 0;
sumrigth = 0;
sumtemp = 0;
pressed = 0;
step = 1;

for a in s :
    if (a == '^') :
        pressed = 1;
        step = 1;
    else :
        if (a == '=') : a = 0;
        else : a = int(a);

        if (pressed == 0) :
            sumleft += sumtemp + a;
            sumtemp += a;
        if (pressed == 1) :
            sumrigth += step * a;
            step = step + 1;


if (sumleft == sumrigth) :
    print ("balance");
if (sumleft > sumrigth) :
    print ("left");
if (sumleft < sumrigth) :
    print ("right");