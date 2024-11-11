sx,sy,tx,ty=map(int,input().split())
x=tx-sx
y=ty-sy
ans=""

ans="U"*y + "R"*x
ans+="D"*y + "L"*x

ans+="L"+"U"*(y+1)+"R"*(x+1)+"D"
ans+="R"+"D"*(y+1)+"L"*(x+1)+"U"
print(ans)
