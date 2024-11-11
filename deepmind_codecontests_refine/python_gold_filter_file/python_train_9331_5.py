s=0;
o=input().rstrip().split(' ')
q=input().rstrip().split(' ')
y_m=int(q[0])
g_m=int(q[1])
b_m=int(q[2])
y_c=(y_m*2)+(g_m);
b_c=(g_m) + (b_m*3)
if y_c > int(o[0]):
    s=s+(y_c-int(o[0]))
if b_c > int(o[1]):
    s=s+(b_c-int(o[1]))
print(s)
