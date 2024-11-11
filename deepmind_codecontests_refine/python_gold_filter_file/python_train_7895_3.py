sx,sy,tx,ty=map(int,input().split())
y=tx-sx
x=ty-sy
path=""
path+="U"*x+"R"*y+"D"*x+"L"*y
path+="L"+"U"*(x+1)+"R"*(y+1)+"D"+"R"+"D"*(x+1)+"L"*(y+1)+"U"
print(path)