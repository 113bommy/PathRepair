sx,sy,tx,ty=map(int,input().split())
x=tx-sx
y=ty-sy
ans=""

ans="U"*y + "R"*x
ans+="D"*y + "L"*x

ans+="L"+"U"*(x+1)+"R"*(y+1)+"D"
ans+="R"+"D"*(x+1)+"L"*(y+1)+"U"
print(ans)
