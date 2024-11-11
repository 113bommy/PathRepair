x, y, u, v = map(int, input().split())
x=u-x
y=v-y

ans  = "L"+"U"*(y+1)+"R"*(x+1)+"D"
ans += "L"*x+"D"*y
ans += "R"*x+"U"*y
ans += "R" + "D"*(x+1)+"L"*(y+1)+"U"
print(ans)
