s = input()
S = s.split()
a = int(S[0])
b = int(S[1])
steps = 0
if a == 1 and b == 1:
    print(0)
else:
    while a>0 and b>0:
        if a>b:
            a-=2
            b+=1
            steps+=1
        else:
            b-=2
            a+=1
            steps+=1

print(steps)
