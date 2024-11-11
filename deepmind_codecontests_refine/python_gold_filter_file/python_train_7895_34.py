sx,sy,tx,ty=map(int,input().split())
print("R"*(tx-sx)+"U"*(ty-sy)+"L"*(tx-sx)+"D"*(ty-sy)+"D"+"R"*(tx-sx+1)+"U"*(ty-sy+1)+"L"+"U"+"L"*(tx-sx+1)+"D"*(ty-sy+1)+"R")