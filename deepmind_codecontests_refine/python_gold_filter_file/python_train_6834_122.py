k = int(input());
s = "";
while k > 0:
    if k > 1:
        s = s + "8";
        k = k - 2;
    else:
        s = s + "4";
        k = k - 1;
if len(s) < 19:
    print(s);
else:
    print(-1);