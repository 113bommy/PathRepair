s=input()
y=s
n=len(s)
m=1
c=0
for i in range(0,n-2):
    if s[i]=="_" and i==0:
        c=1
        m*=9
    elif s[i]=="_":
        c=1
        m*=10
# if c==0:
#     m=0
val=0
re=m
if s.count("X")==n and n!=1:
    print(0)
elif n==2 and (s[-2:]=="__" or s[-2:]=="_X"):
    print(3)
elif n==1 and (s[0]=='0' or s[0]=="_" or s[0]=="X"):
    print(1)
elif n==1 or s[0]=="0":
    print(0)
elif "X" in s:
    if s[0]=="X":
        for i in ['1','2','3','4','5','6','7','8','9']:
            s=y
            m=re
            s=s.replace("X",i)

            if (s[-1]=="X" and s[-2]=="X") or (s[-1]=="X" and s[-2]=="_"):
                m=m
            elif s[-2]=="_" and s[-1]=="X":
                m=m*2
            elif s[-1]=="_" and s[-2]=="_":
                m=m*4
            elif s[-2]=="_" and s[-1] in ['5','0']:
                m=m*2
            elif s[-2] in ['2','5','7','0'] and s[-1]=="_":
                m=m
            elif s[-2:]=="25" or s[-2:]=="75" or s[-2:]=="50" or s[-2:]=="00":
                m=m
            else:
                m=0
            val += m
        print(val)
    else:
        for i in ['1','2','3','4','5','6','7','8','9','0']:
            s=y
            m = re
            s=s.replace("X",i)
            if (s[-1]=="X" and s[-2]=="X") or (s[-1]=="X" and s[-2]=="_"):
                m=m
            elif s[-2]=="_" and s[-1]=="X":
                m=m*2
            elif s[-1]=="_" and s[-2]=="_":
                m=m*4
            elif s[-2]=="_" and s[-1] in ['5','0']:
                m=m*2
            elif s[-2] in ['2','5','7'] and s[-1]=="_":
                m=m
            elif s[-2:]=="25" or s[-2:]=="75" or s[-2:]=="50" or s[-2:]=="00":
                m=m
            else:
                m=0
            val += m
        print(val)

else:
    if (s[-1] == "X" and s[-2] == "X") or (s[-1] == "X" and s[-2] == "_"):
        m = m
    elif s[-2] == "_" and s[-1] == "X":
        m = m * 2
    elif s[-1] == "_" and s[-2] == "_":
        m = m * 4
    elif s[-2] == "_" and s[-1] in ['5', '0']:
        m = m * 2
    elif s[-2] in ['2', '5', '7'] and s[-1] == "_":
        m = m
    elif s[-2:] == "25" or s[-2:] == "75" or s[-2:] == "50" or s[-2:] == "00":
        m = m
    else:
        m = 0
    print(m)