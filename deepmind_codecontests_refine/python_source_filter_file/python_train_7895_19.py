sx, sy, tx, ty=map(int, input().split())
print("D"+"R"*(tx-sx+1)+"U"*(ty-sy+1)+"L"*(tx-sx+1)+"D"*(tx-sx)+
      "L"+"U"*(ty-sy+1)+"R"*(tx-sx+1)+"D"*(tx-sx+1)"L"*(tx-sx))