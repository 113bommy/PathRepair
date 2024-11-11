t = input();
t = int(t);
n =[];
for i in range(t):

    s,a,b,c = input().split();
    s = int(s);
    a = int(a);
    b = int(b);
    c = int(c);
    totalchoc = s*c;
    z = totalchoc//a;
    x = z*b;
    totalchoc = totalchoc+x;
    n.append(totalchoc);
for i in range(t):
    print(n[i]);