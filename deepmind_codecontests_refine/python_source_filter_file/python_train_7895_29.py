sx,sy,tx,ty=map(int,input().split())
x=tx-sx
y=ty-sy
ans=""

ans="U"*x + "R"*y
ans+="D"*x + "L"*y

ans+="L"+"U"*(x+1)+"R"*(x+1)+"D"
ans+="R"+"D"*(x+1)+"L"*(y+1)+"U"
print(ans)
