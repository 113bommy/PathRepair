Fn,Ln=input().lower().split()
R = Fn[0]
for i in Fn[1:]:
    if i<=R[-1]:
        R+=i
    else:
        break
R += Ln[0]
print(R)