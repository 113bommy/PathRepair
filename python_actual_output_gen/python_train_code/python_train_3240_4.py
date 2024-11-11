#brute force, graph, math, DIV-2
A,B,C = map(int, input().split())
x = y = (A-C+B) / 2
z = (C-A+B) / 2
if(x%1!=0 or z%1!=0 or x<0 or z<0 or C-int(z)< 0):
    print("IMPOSSIBLE")
else:
    print(int(x),int(z),C-int(z)) 
