a,b,c,d=map(int,input().split())
x=c-a
y=d-b
print("U"*y+"R"*x+"D"*y+"L"*x+"L"+"U"*(y+1)*"R"*(x+1)+"D"+"R"+"D"*(y+1)+"L"*(x+1)+"U")