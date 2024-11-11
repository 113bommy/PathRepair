sx,sy,tx,ty=map(int, input().split()) #a1 a2 a3

m1=(tx-sx)*"R"+(ty-sy)*"U"
m2=(tx-sx)*"L"+(ty-sy)*"D"


print(m1+m2+"DR"+m1+"ULUL"+m2+"DR")