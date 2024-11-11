sx,sy,tx,ty=map(int,input().split())
a=tx-sx
b=ty-sy
ans=""

ans="U"*b+"R"*a
ans+="D"*b+"L"*a

ans+="D"+"R"*(a+1)+"U"*(b+1)+"L"
ans+="U"+"L"*(a+1)+"D"*(b+1)+"R"

print(ans)
