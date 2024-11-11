sx,sy,tx,ty = map(int, input().split())
x = tx-sx
y = ty-sy
a = "R"*x+"U"*y
b = "L"*x+"D"*y
c = "D+""R"*(x+1)+"U"*(y+1)+"L"
d = "U"+"L"*(x+1)+"D"*(y+1)+"R"
print(a+b+c+d)