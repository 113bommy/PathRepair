n, k, l, c, d, p, nl, np=map(int,input().strip().split())
a1=k*l
m1=a1//3
lime=c*d
salt=p//np
a2=min(m1,lime,salt)
print(a2//3)
