sx,sy,tx,ty = map(int,input().split())
x = tx-sx
y = ty-sy
a = "R"*x+"U"*y+"L"*x+"D"*y+"L"+"U"*(y+1)+"R"*(x+1)+"DR"+"D"*(y+1)+"L"*(x+1)+"U"
print(a)