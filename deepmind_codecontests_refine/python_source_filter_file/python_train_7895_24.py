sx,sy,tx,ty=map(int,input().split())
dx,dy=tx-sx,ty-sy
print("U"*dy+"R"*dx+"D"*dx+"L"*dy+"L"+"U"*(dy+1)+"R"*(dx+1)+"D"+"R"+"D"*(dy+1)+"L"*(dx+1)+"U")