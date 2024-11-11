sx,sy,tx,ty = map(int,input().split())
dx = tx-sx
dy = ty-sy

print("R"*dx+"U"*dy+"R"+"D"*(dy+1)+"L"*(dx+1) +"U"\
    +"U"*dy+"R"*dx+"U"+"L"*(dx+1)+"D"*(dy+1) +"R" )
