n=int(input())
mx=5*(10**9)
mn=-10**9
flag = True

for i in range(n):
   c,d=map(int,input().split())
   
   if d==1: mn=max(mn,1900)
   else:    mx=min(mx,1899)
   
   if mn>mx: flag=False           #besi poriman barar poro div_2 othoba besi komar poro jodi div_1 dekhay
   mn+=c;mx+=c

if not flag:print("impossible")
else:
    if mx>10**9:print("Infinity") #'mx' er sathe je kono number jog biog er poro jeno sothik condition break na kore
    else:print(mx)                #'d==2' kokhono na thakle 'infinity'
