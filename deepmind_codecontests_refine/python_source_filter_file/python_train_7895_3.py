sx,sy,tx,ty=map(int,input().split())
x=tx-sx
y=ty-sy
path=""
path+="U"*x+"R"*y+"D"*x+"L"*y
path+="L"+"R"*(x+1)+"U"*(y+1)+"L"+"U"+"L"*(x+1)+"D"*(y+1)+"R"
print(path)