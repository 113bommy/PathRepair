sx, sy, gx, gy = map(int, input().split())

print("U"*(gy-sy)+"R"*(gx-sx)+"D"*(gy-sy)+"L"*(gx-sx)+"L"+"U"*(gy-sy+1)+"R"*(gx-sx+1)+"D"+"R"+"D"*(gy-sy+1)+"L"*(gx-sx+1)+"U")